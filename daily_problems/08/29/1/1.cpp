#include <bits/stdc++.h>

using namespace std;


void solve(string s, string t) {
    int n = s.size(), m = t.size();
    string ans = "";
    vector<vector<int>> memo(n, vector<int> (m, -1));
    function<int(int, int)> f = [&](int i, int j) -> int {
        if (i == n || j == m) return 0;
        if (memo[i][j] != -1) return memo[i][j];
        f(i+1, j); f(i, j+1);
        int c = s[i] == t[j] ? f(i+1, j+1) + 1 : 0;
        if (c > ans.length()) ans = s.substr(i, c);
        return memo[i][j] = c;
    };
    f(0, 0);
    cout << ans.length() << '\n' << ans << '\n';
}


int main() {
    string s, t; while(cin >> s >> t)
    solve(s, t);
}