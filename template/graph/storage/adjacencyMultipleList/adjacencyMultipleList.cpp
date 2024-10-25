#include <bits/stdc++.h>

using namespace std;


struct Edge {
    int x, y;
    Edge* nextX, *nextY;
    Edge(): x(0), y(0), nextX(nullptr), nextY(nullptr) {}
    Edge(int _x, int _y): x(_x), y(_y), nextX(nullptr), nextY(nullptr) {}
    Edge(int _x, int _y, Edge *_nextX, Edge *_nextY): x(_x), y(_y), nextX(_nextX), nextY(_nextY) {}
};

struct Vertex {
    int val;
    Edge *next;
    Vertex(): val(0), next(nullptr) {} 
    Vertex(int _val): val(_val), next(nullptr) {} 
    Vertex(int _val, Edge *_next): val(_val), next(_next) {} 
};

int main() {
    //n个顶点和m条边
    int n, m, u, v; cin >> n >> m;
    vector<Vertex> vertexes(n);
    for(int i = 0; i < n; i++) {
        vertexes[i] = Vertex(i);
    }

    //建图
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        Edge *e = new Edge(u, v, vertexes[u].next, vertexes[v].next);
        vertexes[u].next = e;
        vertexes[v].next = e;
    }
}