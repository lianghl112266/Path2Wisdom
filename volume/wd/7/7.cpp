#include <bits/stdc++.h>
#include <tree.h>
using namespace std;


int main() {
    freopen("input.txt", "r", stdin);
    // 建树
    int n; cin >> n;
    vector<int> pre(n); for(int i = 0; i < n; i++) cin >> pre[i];
    vector<int> in(n); for(int i = 0; i < n; i++) cin >> in[i];
    Node *root = build(pre, in);


    //solve
    function<int(Node*)> f = [&](Node *p) -> int {
        if (!p) return 0;
        // 这里正常逻辑是遍历所有右链， 转念一想， 每个右孩子都会遍历右链， 所以只用右孩子即可
        int l = f(p->left), r = f(p->right);
        return max(l + 1, r);
    };
    cout << f(root) << '\n';

}