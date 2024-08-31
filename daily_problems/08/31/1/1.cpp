#include <bits/stdc++.h>

using namespace std;



bool solve(vector<vector<int>> edges, int n) {
    vector<vector<int>> g(n);
    for(auto e: edges) g[e[0]].push_back(e[1]);
    vector<bool> vis(n, false);
    function<void(int)> f = [&](int x) -> void {
        vis[x] = true;
        for(auto y: g[x]) if (!vis[x]) f(y);
    };
    for(auto v: vis) if (!v) return false;
    return true;
}


int main() {

}