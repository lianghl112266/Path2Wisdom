#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f;

void solve(int m, int n, vector<int> a) {
    vector<vector<int>> memo(n, vector<int> (m+1, -1));
    function<int(int, int)> f = [&](int i, int r) -> int {
        if (i < 0 || r < 0) return inf;
        if (r == a[i]) return 1;
        if (memo[i][r] != -1) return memo[i][r];
        return memo[i][r] = min(f(i-1, r), r > a[i] ? f(i-1, r - a[i]) + 1: inf);
    };
    int res = f(n-1, m);
    cout << (res < inf ? res : 0) << '\n';
}

int main() {
    int m, n; 
    while(cin >> m >> n) {
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        solve(m, n, a);
    }
}