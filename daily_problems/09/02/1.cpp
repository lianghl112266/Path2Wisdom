#include <bits/stdc++.h>

using namespace std;

// 天勤模拟卷 第八套
void solve(vector<vector<int>> edges, int n) {
    vector<vector<pair<int, int>>> g(n);
    vector<int> deg(n);
    for(auto e: edges) {
        int x = e[0], y = e[1], w = e[2];
        g[x].push_back({y, w});
        deg[y]++;
    }
    vector<int> memo(n, -1);
    function<int(int, int)> f = [&](int x, int fa) -> int {
        if (memo[x] != -1) return memo[x];
        int res = 0;
        for(auto &[y, w]: g[x]) if (y != fa) res = max(res, f(y, x) + w);
        return memo[x] = res;
    };

    int ans = 0;
    for(int i = 0; i < n; i++) if (deg[i] == 0) ans = max(ans, f(i, -1));
    cout << ans << '\n';
}


int main() {

}