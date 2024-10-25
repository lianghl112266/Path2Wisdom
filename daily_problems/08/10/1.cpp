#include <bits/stdc++.h>

using namespace std;

/**
 * 来自王道教材5.4图的应用小结第7题  
 * 
 * 
 * 时间复杂度O(n), 空间复杂度O(n)  
 */


void solve(int n, vector<vector<int>> edges) {
    vector<vector<int>> g(n);
    vector<int> deg(n);
    for (auto e: edges) {
        int x = e[0], y = e[1];
        g[x].emplace_back(y);
        deg[y]++;
    }

    //dfs
    function<void(int)> f = [&](int x) -> void {
        cout << x << " ";
        for(auto y: g[x]) if (--deg[y] == 0) {
            f(y);
            deg[y]--;  //省略vis数组
        }
    };

    for(int i = 0; i < n; i++) if(deg[i] == 0) f(i);
}


int main() {
    solve(4, {{0, 1}, {0, 2}, {2, 1}, {1, 3}, {2, 3}});
}
