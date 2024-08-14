#include <bits/stdc++.h>

using namespace std;

void debugVec(vector<int> a) {for(auto x: a) cout << x << " ";cout << endl;}

vector<int> solve(int n, vector<vector<int>> edges, int start) {
    //建图
    vector<vector<int>> g(n, vector<int>(n, INT_MAX/2));
    for(auto e: edges) {
        int x = e[0], y = e[1], w = e[2];
        g[x][y] = w;
    }
    //初始化数据结构
    vector<int> dis(n, INT_MAX/2);
    vector<bool> vis(n, false);
    dis[start] = 0;

    //dijkstra
    while(true) {
        int x = -1;
        for(int i = 0; i < n; i++) {
            if (!vis[i] && (x == -1 || dis[i] < dis[x])) x = i;
        }
        if (x == -1) break;
        vis[x] = true;
        for(int y = 0; y < n; y++) dis[y] = min(dis[y], dis[x] + g[x][y]);
    }

    return dis;
}


int main() {
    int n, m, x, y, w, s; cin >> n >> m >> s;
    vector<vector<int>> edges;
    for(int i = 0; i < m; i++) {
        cin >> x >> y >> w;
        edges.push_back({x, y, w});
    }
    auto ans = solve(n, edges, 0);
    for(auto x: ans) cout << x << " ";
}