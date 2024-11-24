#include <bits/stdc++.h>
#include <tree.h>

using namespace std;



void solve(Node *root) {
    if (!root) return;
    vector<int> mi;
    vector<Node*> q {root};
    while (!q.empty()) {
        int x = INT_MAX;
        for (auto v: q) x = min(x, v->val);
        mi.push_back(x);
        vector<Node*> p(q);
        q.clear();
        for (auto o: p) {
            if (o->left) q.push_back(o->left);
            if (o->right) q.push_back(o->right);
        }
    }

    for (auto v: mi) cout << v << ' ';
}



int main() {
    freopen("input.txt", "r", stdin);

    int n; cin >> n;
    vector<int> pre(n); for(int i = 0; i < n; i++) cin >> pre[i];
    vector<int> in(n); for(int i = 0; i < n; i++) cin >> in[i];
    Node *root = build(pre, in);
    solve(root);
}