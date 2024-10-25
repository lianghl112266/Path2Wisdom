/**
 * 
 * 来自王道绿书P114算法章节图第三题
 * 
 * 
 * 
 * 
 * 红蓝染色法， 会遍历图就行
 * 
 * 时间复杂度O(n^2), 空间复杂度O(n)
 * 
 * 
 */



#include <bits/stdc++.h>

using namespace std;

//#define TREE
#define GRAPH_ADJMAT

#ifdef TREE
typedef struct node {
    int data;
    struct node *lchild, *rchild;
    node(): data(0), lchild(nullptr), rchild(nullptr) {}
    node(int _data, node *l, node *r): data(_data), lchild(l), rchild(r){}
} BTNode;
#endif

#ifdef GRAPH_ADJMAT
const int MAXV = 100;
typedef struct {
    int numV, numE;
    char VerticesList[MAXV];
    int Edge[MAXV][MAXV];
} MGraph;
#endif



bool solve(MGraph *g) {
    int n = g->numV;
    if (n == 0) return true;
    int red = 1, blue = -1;
    vector<int> color(n);
    vector<int> q{0};
    color[0] = red;
    while(!q.empty()) {
        vector<int> p(q);
        q.clear();
        for (auto x: p) {
            for(int y = 0; y < n; y++) {
                if (g->Edge[x][y] != 0) { //这里假设权值不为0即有边
                    if (color[y] == color[x]) return false;
                    if (color[y] == 0) {
                        q.push_back(y);
                        color[y] = -color[x];
                    }

                }
            }
        }
    }
    return true;
}