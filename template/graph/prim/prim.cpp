#include <bits/stdc++.h>

using namespace std;


int main() {
    // 读入图信息
    freopen("in", "r", stdin);
    int n, m; cin >> n >> m;
    int g[n][n]; memset(g, 0x3f, sizeof(g));
    for(int i = 0; i < m; i++) {
        int x, y, w; cin >> x >> y >> w;
        g[x][y] = w;
        g[y][x] = w;
    }

    int dis[n]; memset(dis, 0x3f, sizeof(dis));
    int vis[n]; memset(vis, false, sizeof(vis));
    dis[0] = 0;
    int from[n]; memset(from, 0, sizeof(from));
    from[0] = -1;
    int weight = 0;
    
    while(1) {
        int x = -1;
        for(int i = 0; i < n; i++) if (!vis[i] && (x == -1 || vis[i] < vis[x])) x = i;
        if (x == -1) break;
        if (from[x] != -1) weight += g[from[x]][x];
        // cout << from[x] << ' ' << x << '\n'; 如果要看选的边， 解开这行注释
        vis[x] = true;
        // 和dijkstra唯一区别
        for(int y = 0; y < n; y++) {
            if (g[x][y] < dis[y]) { // 这里需要记录从那条边过来的， 后续方便统计权值
                dis[y] = g[x][y];
                from[y] = x;
            }
        }
    }

    cout << weight << '\n';
}