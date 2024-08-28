#include <bits/stdc++.h>

using namespace std;


void solve(string s, string t) {
    int n = s.size(), m = t.size();
    string ans = "";
    vector<vector<int>> memo(n, vector<int> (m, -1));
    function<int(int, int)> f = [&](int i, int j) -> int {
        if (i >= n || j >= m) return 0;
        if (memo[i][j] != -1) return memo[i][j];
        f(i+1, j);
        f(i, j+1);
        int common = s[i] == t[j] && !isdigit(s[i]) ? f(i+1, j+1) + 1 : 0;
        if (common > ans.length()) ans = s.substr(i, common);
        return memo[i][j] = common;
    };
    f(0, 0);
    cout << ans << '\n';
}


// 上交2018 Problem B
int main() {
    string s, t; while(cin >> s >> t)
    solve(s, t);
}