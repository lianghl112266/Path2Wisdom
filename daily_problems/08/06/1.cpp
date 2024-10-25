/**
 * 来自王道课本第六章图， 图的遍历小结， 第三题
 * 时间复杂度O(n), 空间复杂度O(n)
 * 思路： DFS
 */



#include <bits/stdc++.h>

using namespace std;

bool solve(int n, vector<vector<int>> edges) {
    if (edges.size() != n-1) return false;
    //建图
    vector<vector<int>> g(n);
    for (auto e: edges) {
        int x = e[0], y = e[1];
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    //判断是否是树
    vector<bool> vis(n, false);
    vector<int> q{0};
    vis[0] = true;
    function<bool(int, int)> f = [&](int x, int fa) -> bool {
        bool res = true;
        for(auto y: g[x]) {
            if (y != fa) {
                if (vis[y]) return false;
                vis[y] = true;
                res = res && f(y, x);
            }
        }
        return res;
    };
    return f(0, -1);
}


int main() {
    cout << solve(4, {{0, 1}, {0, 2}, {1, 2}}) << '\n'; //0
    cout << solve(4, {{0, 1}, {0, 2}, {1, 3}}) << '\n'; //1
}