/**
 * 
 * 来自王道绿书P112算法章节树第四题
 * 
 * 
 * 
 * 
 * 层序遍历就行了
 * 
 * 时间复杂度O(n), 空间复杂度O(n)
 * 
 * 
 */



#include <bits/stdc++.h>

using namespace std;

#define TREE

#ifdef TREE
typedef struct node {
    int data;
    struct node *lchild, *rchild;
    node(): data(0), lchild(nullptr), rchild(nullptr) {}
    node(int _data, node *l, node *r): data(_data), lchild(l), rchild(r){}
} BTNode;
#endif


int solve(node *root) {
    if (!root) return 0;
    int s = 0;
    vector<node*> q{root};
    for(int d = 1; !q.empty();  d++) {
        s += d * q.size();
        vector<node*> p(q);
        q.clear();
        for(auto x: p) {
            if (x->lchild) q.push_back(x->lchild);
            if (x->rchild) q.push_back(x->rchild);
        }
    }
    return s;
}