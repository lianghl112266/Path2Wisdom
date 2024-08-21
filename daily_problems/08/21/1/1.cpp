#include <bits/stdc++.h>


using namespace std;


const int inf = 0x3f3f3f3f;

void solve(int n, int y, vector<vector<int>> edges) {
    vector<vector<int>> g(n, vector<int>(n, -1));
    int r = -inf, l = inf;
    for(auto e: edges) {
        int u = e[0], v = e[1], w = e[2];
        g[u][v] = w;
        r = max(r, w);
        l = min(l, w);
    }

    auto check = [&](int thr) -> bool {
        int cnt = 1;
        vector<int> q {0};
        vector<bool> vis(n);
        vis[0] = true;
        while (!q.empty()) {
            vector<int> p(q);
            q.clear();
            for(auto x: p) {
                for(int y = 0; y < n; y++) {
                    if (!vis[y] && g[x][y] >= thr) {
                        cnt++;
                        vis[y] = true;
                        q.push_back(y);
                    }
                }
            }
        }
        return cnt <= y;
    };


    auto bisect = [&](int i, int j) {
        while(i <= j) {
            int mid = (i+j)/2;
            if (!check(mid)) i = mid + 1;
            else j = mid - 1;
        }
        return i;
    };
    
    cout << bisect(l, r) << endl;
}



int main() {
    int T; cin >> T;
    while(T--) {
        int n, y; cin >> n >> y;
        vector<vector<int>> edges(n-1);
        for(int i = 0; i < n-1; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            edges[i] = {u, v, w};
        }
        solve(n, y, edges);
    }
}

//题解： 二分