#include <bits/stdc++.h>

using namespace std;


int main() {
    // 读入图信息
    freopen("in", "r", stdin);
    int n, m, start; cin >> n >> m >> start;
    int g[n][n]; memset(g, 0x3f, sizeof(g));
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        g[x][y] = 1;
        g[y][x] = 1;
    }

    int dis[n]; memset(dis, 0x3f, sizeof(dis));
    dis[start] = 0;
    vector<int> q {start};
    for(int level = 1; !q.empty(); level++) {
        vector<int> p(q);
        q.clear();
        for(auto x: p) {
            for(int y = 0; y < n; y++) if (g[x][y] != 0 && dis[y] == 0x3f3f3f3f) { // 因为有dis， 所以这里可以不用vis数组
                dis[y] = level;
                q.push_back(y);
            }
        }
    }

    for(int i = 0; i < n; i++) cout << dis[i] << ' ';
}