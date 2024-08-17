#include <bits/stdc++.h>

using namespace std;


void solve(int n, vector<vector<int>> edges, vector<double> succProb, int start, int end) {
    vector<vector<double>> g(n, vector<double> (n));
    for(int i = 0; i < edges.size(); i++) {
        double x = edges[i][0], y = edges[i][1], w = succProb[i];
        g[x][y] = w;
        g[y][x] = w;
    }

    vector<bool> vis(n);
    vector<double> dis(n);
    vector<int> pa(n);
    pa[start] = start;
    dis[start] = 1;
    while(true) {
        int x = -1;
        for(int i = 0; i < n; i++) {
            if (!vis[i] && (x == -1 || dis[i] > dis[x])) x = i;
        }
        if (x == -1 || x == end) break;
        vis[x] = true;
        for(int y = 0; y < n; y++) {
            if (dis[y] <= dis[x] * g[x][y]) {
                dis[y] = dis[x] * g[x][y];
                pa[y] = x;
            }
        }
    }

    function<void(int)> printPath = [&](int x) -> void {
        if (x != start) printPath(pa[x]);
        cout << x << " ";
    };
    printPath(end);
    cout << endl;
    cout << dis[end] << endl;
}


int main() {
    int n, x, y; cin >> n;
    vector<vector<int>> edges(n);
    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        edges[i] = {x, y};
    }
    vector<double> succProb(n);
    for(int i = 0; i < n; i++) {
        double x;
        cin >> x;
        succProb[i] = x;
    }
    cin >> x >> y;

    solve(n, edges, succProb, x, y);
}