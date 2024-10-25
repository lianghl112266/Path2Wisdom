#include <bits/stdc++.h>

using namespace std;


const int MAXV = 100;

struct ArcNode {
    int adjvex;
    ArcNode *nextarc;
    ArcNode(int _adjvex, ArcNode *_nextarc): adjvex(_adjvex), nextarc(_nextarc) {}
};

struct VNode {
    int data;
    ArcNode *firstarc;
};

struct MGraph {
    VNode AdjList[MAXV];
    int vexnum, arcnum;
};


/**
 * 做法一：并查集
 * 判断遍历完的并查集数量，为1就是联通
 * 时间复杂度O(n+m*a(m))，空间复杂度O(max(n, m)), a(m)为一个增长缓慢的函数， 通常小于4
 * 
 */
int solve(MGraph *g) {
    int n = g->vexnum;
    vector<int> pa(n);
    for(int i = 0; i < n; i++) pa[i] = i;
    function<int(int)> find = [&](int x) -> int {
        if(pa[x] != x) pa[x] = find(pa[x]);
        return pa[x];
    };

    auto merge = [&](int x, int y) {
        int rootX = find(x), rootY = find(y);
        pa[rootX] = rootY;
    };

    for(int i = 0; i < n; i++) {
        VNode v = g->AdjList[i];
        for(ArcNode *p = v.firstarc; p; p = p->nextarc) merge(i, p->adjvex);
    }

    int cnt = 0;
    for(int i = 0; i < n; i++) if (i == pa[i]) cnt++;
    return cnt == 1;
}


/**
 * 做法二：广搜
 * 如果是一个连通集，那么一次遍历就可以访问全部节点
 * 时间复杂度O(n+m)，空间复杂度O(m)
 * 
 */
int solve1(MGraph *g) {
    int n = g->vexnum;
    vector<bool> vis(n, false);
    vector<int> q{0};
    vis[0] = true; 
    while (!q.empty()) {
        vector<int> p(q);
        q.clear();
        for(auto x: p) {
            vis[x] = true;
            for (ArcNode* e =  g->AdjList[x].firstarc; e; e = e->nextarc) {
                if (!vis[e->adjvex]) {
                    vis[e->adjvex] = true;
                    q.emplace_back(e->adjvex);
                }
            } 
        }
    }
    for(auto v: vis) if (!v) return false;
    return true;
}


int main() {
    int n, m, u, v; cin >> n >> m;
    MGraph *g = new MGraph();
    g->vexnum = n; g->arcnum = m;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        ArcNode *uu = new ArcNode(u, g->AdjList[v].firstarc);
        ArcNode *vv = new ArcNode(v, g->AdjList[u].firstarc);
        g->AdjList[v].firstarc = uu;
        g->AdjList[u].firstarc = vv;
    }

    cout << solve1(g);
}