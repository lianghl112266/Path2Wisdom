#include <bits/stdc++.h>


using namespace std;


int main() {
    //建图
    freopen("input.txt", "r", stdin);
    int n, m, x; cin >> n >> m >> x;
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        g[x].push_back(y);
    }

    //solve
    int cnt = 0;
    for(int i = 0; i < n; i++) for(int j = 0; j < g[i].size(); j++) if (g[i][j] == x) cnt++;

    cout << cnt << '\n';
}