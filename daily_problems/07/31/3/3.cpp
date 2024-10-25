/**
 * 
 * 来自王道绿书算法章节树第四题P112
 * 
 * 
 * 时间复杂度O(n/2 *log n)
 * 空间复杂度O(log n)
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


//做法1
int f(BTNode *root) {
    if (!root) return 0;
    int cnt = 0;
    for(BTNode *p = root; p; p = p->rchild) cnt++;
    return max(f(root->lchild), cnt);
}



//王道做法
// 时间复杂度O(n)
// 空间复杂度O(log n)
int f2(BTNode *root) {
    int mx = 0;
    function<int(BTNode*)> f = [&](BTNode *root) -> int {
        if (!root) return 0;
        int deg = max(f(root->lchild), f(root->rchild)+1);
        mx = max(mx, deg);
        return deg;
    };
    f(root);
    return mx;
}

int main() {
    BTNode *root = new BTNode();
    root->lchild = new BTNode();
    root->lchild->lchild = new BTNode();
    root->lchild->rchild = new BTNode();
    root->lchild->rchild->rchild = new BTNode();
    root->lchild->lchild->rchild = new BTNode();
    root->lchild->lchild->rchild->rchild = new BTNode();
    root->lchild->lchild->rchild->rchild->rchild = new BTNode();
    root->lchild->lchild->rchild->rchild->rchild->rchild = new BTNode();
    root->lchild->lchild->rchild->rchild->rchild->rchild->rchild = new BTNode();
    
    cout << f(root) << endl;
    cout << f2(root) << endl;
}