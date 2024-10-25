#include <bits/stdc++.h>

using namespace std;


void solve(int l, int r) {
    auto f = [](int x) -> int {
        string s = to_string(x);
        int n = s.length();
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(10, vector<int> (3, -1)));

        function<int(int, int, int, bool)> dfs = [&](int i, int x, int cnt, bool limit) -> int {
            if (i == n) return cnt == 2;
            if (!limit && memo[i][x][cnt] != -1) return memo[i][x][cnt];
            int res = 0;
            int up = limit ? s[i] - '0' : 9;
            if (cnt == 0) { //之前没选过
                for(int d = 1; d <= up; d++) {
                    res += dfs(i+1, d, min(cnt+1, 2), limit && d == up);
                }
                res += dfs(i+1, x, cnt, false); // 继续不选
            }else { //选过
                if (0 < x && x <= up + 1) res += dfs(i+1, x-1, min(cnt+1, 2), limit && x-1 == up); //能往下取
                if (x < up) res += dfs(i+1, x+1, min(cnt+1, 2), limit && x+1 == up); //能往上取
            }
            if (!limit) memo[i][x][cnt] = res;
            return res;
        };

        return dfs(0, 0, 0, true);
    };
    
    cout << f(r) - f(l-1) << endl;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int T; cin >> T;
    while(T--) {
        int l, r;
        cin >> l >> r;
        solve(l, r);
    }
}

//数位dp