#include <bits/stdc++.h>

using namespace std;


void solve(string s, vector<string> ss) {
    auto f = [&](string s1, string s2) -> int {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> memo(n, vector<int>(m, -1));
        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (i < 0 || j < 0) return 0;
            int &res = memo[i][j];
            if (res != -1) return res;
            if (s1[i] == s2[j]) return res = dfs(i-1, j-1) + 1;
            return res = max(dfs(i-1, j), dfs(i, j-1));
        };
        return dfs(n-1, m-1);
    };

    int ans = 0;
    int idx = 0;
    for(int i = 0; i < ss.size(); i++) {
        int v = f(s, ss[i]);
        if (v > ans) {
            ans = v;
            idx = i;
        }
    }
    cout << ss[idx] << '\n' << ans;
}

int main() {
    string s;
    int n;
    cin >> s >> n;
    vector<string> ss(n);
    for(int i = 0; i < n; i++) cin >> ss[i];
    solve(s, ss);
}