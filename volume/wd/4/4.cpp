#include <bits/stdc++.h>
#include <tree.h>

using namespace std;

int main() {
    // 建树
    //树1
    int n; cin >> n;
    vector<int> pre(n); for(int i = 0; i < n; i++) cin >> pre[i];
    vector<int> in(n); for(int i = 0; i < n; i++) cin >> in[i];
    Node *root1 = build(pre, in);
    //树2
    cin >> n;
    pre.resize(n); for(int i = 0; i < n; i++) cin >> pre[i];
    in.resize(n); for(int i = 0; i < n; i++) cin >> in[i];
    Node *root2 = build(pre, in);

    //solve
    function<bool(Node*, Node*)> f = [&](Node *p, Node *q) -> bool {
        if (p == q) return true;
        if (!p || !q) return false;
        return f(p->left, q->right) && f(p->right, p->left);
    };

    cout << f(root1, root2) << '\n';
}