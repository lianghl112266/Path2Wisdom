#include <bits/stdc++.h>

using namespace std;


int main() {
    // 读入图信息
    freopen("in", "r", stdin);
    int n, m; cin >> n >> m;
    vector<tuple<int, int, int>> edges;
    for(int i = 0; i < m; i++) {
        int x, y, w; cin >> x >> y >> w;
        edges.emplace_back(x, y, w);
    }

    sort(edges.begin(), edges.end(), [](const tuple<int, int, int> &t1, const tuple<int, int, int> &t2) {return get<2>(t1) < get<2>(t2);});

    // 定义并查集
    int pa[n]; for(int i = 0; i < n; i++) pa[i] = i;
    function<int(int)> find = [&](int x) -> int {
        return pa[x] == x ? pa[x] : pa[x] = find(pa[x]);
    };
    auto merge = [&](int x, int y) -> bool {
        int rx = find(x), ry = find(y);
        pa[rx] = ry;
        return rx != ry;
    };

    int cnt = 0, weight = 0;
    for(auto &[x, y, w]: edges) {
        if (merge(x, y)) { //如果合并成功， 说明找到一条有效边， 当cnt == n-1时， 说明以联通
            // cout << x << ' ' << y << '\n'; 若要看每次选边， 解开这条注释
            weight += w;
            if (++cnt == n-1) break;
        }
    }

    cout << weight << '\n';
}