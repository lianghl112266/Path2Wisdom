#include <bits/stdc++.h>
#include <tree.h>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    int t; cin >> t;
    while(t--) {
        // 建树
        int n; cin >> n;
        vector<int> pre(n); for(int i = 0; i < n; i++) cin >> pre[i];
        vector<int> in(n); for(int i = 0; i < n; i++) cin >> in[i];
        Node *root = build(pre, in);

        //solve
        bool balance = true;
        function<int(Node*)> f = [&](Node *p) -> int {
            if (!p) return 0;
            int l = f(p->left), r = f(p->right);
            balance &= abs(r - l) <= 1;
            return max(l, r) + 1;
        };
        cout << f(root) << ' ' << balance << '\n';
    }
}