/**
 * 
 * 来自王道绿书P112算法章节树第二题
 * 
 */



#include <bits/stdc++.h>

using namespace std;


#define TREE
//#define GRAPH_ADJMAT

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

/**
 * 
 * 递归遍历就行
 * 
 * 时间复杂度O(n), 空间复杂度O(logn)
 */


void solve(BTNode *root, int n) {
    vector<int> a(n, -1);

    function<void(BTNode*, int)> f = [&](BTNode *p, int idx) -> void {
        a[idx] = p->data;
        if (p->lchild) f(root->lchild, (idx+1) * 2 - 1);
        if (p->rchild) f(root->rchild, (idx+1) * 2 + 1 - 1);
    };
    
    if (!root) f(root, 0);
    for(auto x: a) cout << x << " ";
}

