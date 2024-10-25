#include <bits/stdc++.h>

using namespace std;


void solve(int n, vector<int> tree) {
    vector<pair<int, int>> ps {{0, n-1}};
    while (!ps.empty()) {
        vector<pair<int, int>> pss(ps);
        ps.clear();
        for (auto it: pss) {
            int l = it.first, r = it.second;
            cout << tree[l] << ' ';
            if (r > l) {
                int k = r;
                while(tree[k] >= tree[l] && k >= l + 1) k--;
                if (l != k) ps.push_back({l+1, k});
                if (r != k) ps.push_back({k+1, r});
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    
    int n; cin >> n;
    vector<int> tree(n);
    for(int i = 0; i < n; i++) cin >> tree[i];
    solve(n, tree);
}