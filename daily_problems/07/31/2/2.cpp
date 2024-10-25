/**
 * 
 * 来自王道绿书算法章节图第二题P114
 * 
 * 
 * 
 * 
 * 判有环，直接括普排序排序即可,如果最后有度大于1的点， 那就是环上的点, 即有环
 * 
 * 时间复杂度O(n+e), 空间复杂度O(n)
 * 
 * 
 */



#include <bits/stdc++.h>

using namespace std;

const int MAXV = 100;


typedef struct ArcNode {
    int adjvex;
    int data;
    struct ArcNode *nextarc;
} ArcNode;

typedef struct {
    ArcNode *AdjList[MAXV];
    int vexnum, arcnunm;
} MGraph;



bool solve(MGraph *g) {
    int n = g->vexnum;
    vector<int> deg(n);
    for(int i = 0; i < n; i++) for(ArcNode *p = g->AdjList[i]->nextarc; p; p = p->nextarc) deg[p->adjvex]++; //这里假设， 边链带头结点
    vector<int> q;
    for(int i = 0; i < n; i++) if (deg[i] == 0) q.push_back(i);
    while(!q.empty()) {
        vector<int> p(q);
        q.clear();
        for(auto x: p) for(ArcNode *s = g->AdjList[x]->nextarc; s; s = s->nextarc) if (--deg[s->adjvex] == 0) q.push_back(s->adjvex);
    }
    for(auto x: deg) if (x) return true; //有环
    return false;
}