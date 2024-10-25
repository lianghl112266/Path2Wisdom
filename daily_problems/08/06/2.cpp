/**
 * 来自王道课本第六章图， 图的遍历小结， 第五题
 * 时间复杂度O(n), 空间复杂度O(n)
 * 思路：回溯
 */



#include <bits/stdc++.h>

using namespace std;

void solve(int n, vector<vector<int>> edges, int vi, int vj) {
    //建图
    vector<vector<int>> g(n);
    for (auto e: edges) {
        int x = e[0], y = e[1];
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }

    vector<int> path;
    vector<bool> vis(n, false);
    path.emplace_back(vi);
    vis[vi] = true;
    function<void(int)> f = [&](int x) -> void{
        if (x == vj) {
            for(auto x: path) cout << x << " ";
            cout << '\n';
            return;
        }
        for(auto y: g[x]) {
            if (!vis[y]) {
                path.emplace_back(y);
                vis[y] = true;
                f(y);
                vis[y] = false;
                path.pop_back();
            }
        }

    };
    f(vi);
}


int main() {
    solve(4, {{0, 1}, {0, 2}, {1, 2}, {1, 3}, {2, 3}}, 0, 3); //1
}