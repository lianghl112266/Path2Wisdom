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

    // floyd 就这么简单
    for(int k = 0; k < n; k++) for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) cout << g[i][j] << ' ';
        cout << '\n';
    }
}