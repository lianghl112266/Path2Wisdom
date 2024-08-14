#include <bits/stdc++.h>

using namespace std;

void debugVec(vector<int> a) {for(auto x: a) cout << x << " ";cout << endl;}


vector<vector<int>> solve(int n, vector<vector<int>> edges, int start) {
    //建图
    vector<vector<int>> g(n, vector<int>(n, INT_MAX/2));
    for(auto e: edges) {
        int x = e[0], y = e[1], w = e[2];
        g[x][y] = w;
    }

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }

    return g;
}


int main() {
    int n, m, x, y, w, s; cin >> n >> m >> s;
    vector<vector<int>> edges;
    for(int i = 0; i < m; i++) {
        cin >> x >> y >> w;
        edges.push_back({x, y, w});
    }
    auto ans = solve(n, edges, 0);
    for(auto row: ans) debugVec(row);
}