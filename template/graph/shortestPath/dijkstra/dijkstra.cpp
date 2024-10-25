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
    dis[0] = 0; // 源点是1就是 dis[1] = 0;, 本模版默认0是源点
    
    while(1) {
        int x = -1;
        for(int i = 0; i < n; i++) if (!vis[i] && (x == -1 || dis[i] < dis[x])) x = i;
        if (x == -1) break;
        vis[x] = true;
        for(int y = 0; y < n; y++) dis[y] = min(dis[y], dis[x] + g[x][y]);
    }

    for(int i = 0; i < n; i++) cout << dis[i] << ' ';
}