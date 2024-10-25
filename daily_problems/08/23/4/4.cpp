#include <bits/stdc++.h>

using namespace std;


void solve(string s, string t) {
    int n = s.size(), m = t.size();
    vector<vector<int>> memo(n, vector<int> (m, -1));
    function <int(int, int)> f = [&](int i, int j) -> int {
        if (i < 0 || j < 0) return j < 0;
        if (memo[i][j] != -1) return memo[i][j];
        return memo[i][j] = f(i-1, j) + (s[i] == t[j] ? f(i-1, j-1) : 0);
    };
    cout << f(n-1, m-1) << '\n';
}

int main() {
    int n; cin >> n; 
    while(n--) {
        string s, t; cin >> s >> t;
        solve(s, t);
    }
}