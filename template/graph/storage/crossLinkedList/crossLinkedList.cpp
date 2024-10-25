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
    Edge *in, *out;
    Vertex(): val(0), in(nullptr), out(nullptr) {} 
    Vertex(int _val): val(_val), in(nullptr), out(nullptr) {} 
    Vertex(int _val, Edge *_in, Edge *_out): val(_val), in(_in), out(_out) {} 
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
        Edge *e = new Edge(u, v, vertexes[u].out, vertexes[v].in);
        vertexes[u].out = e;
        vertexes[v].in = e;
    }
}