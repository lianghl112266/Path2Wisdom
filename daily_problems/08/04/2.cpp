/**
 * 
 * 来自王道绿书P112算法章节树第6题
 * 
 */



#include <bits/stdc++.h>

using namespace std;


#define TREE
//#define GRAPH_ADJMAT
//#define LINKLIST
#ifdef TREE
typedef struct node {
    int data;
    struct node *lchild, *rchild;
    node(): data(0), lchild(nullptr), rchild(nullptr) {}
    node(int _data, node *l, node *r): data(_data), lchild(l), rchild(r){}
} BTNode;

BTNode* build(vector<int> preOrder, vector<int> inOrder) {
        if(!preOrder.size()) return NULL;

        BTNode * root = new BTNode();
        root->data = preOrder[0];
        root->lchild = root->rchild = NULL;

        if(preOrder.size() == 1) return root;

        vector<int>::iterator it = find(inOrder.begin(), inOrder.end(), preOrder[0]);

        vector<int>pl(preOrder.begin() + 1, preOrder.begin() + 1 + (it - inOrder.begin()));
        vector<int>pr(preOrder.begin() + 1 + (it - inOrder.begin()), preOrder.end());
        vector<int>il(inOrder.begin(), it);
        vector<int>ir(it + 1, inOrder.end());

        root->lchild = build(pl, il);
        root->rchild = build(pr, ir);

        return root;
}

#endif

#ifdef GRAPH_ADJMAT
const int MAXV = 100;
typedef struct {
    int numV, numE;
    char VerticesList[MAXV];
    int Edge[MAXV][MAXV];
} MGraph;
#endif



#ifdef LINKLIST
typedef struct node {
    int data;
    struct node *next;
    node(): data(0), next(nullptr) {}
    node(int _data): data(_data), next(nullptr){}
    node(int _data, node *_next): data(_data), next(_next){}
} *LinkList;

node *build(int n) {
    node *head = new node();
    node *rear = head; int x;
    for(int i = 0; i < n; i++) {
        cin >> x;
        rear->next = new node(x);
        rear = rear->next;
    }
    return head;
}
#endif
/**
 * 递归遍历左右孩子是否对称即可
 * 
 * 时间复杂度O(n), 空间复杂度O(logn)
 */



bool f(BTNode *p1, BTNode *p2) {
    if (!p1 && !p2) return true;
    if (!p1 || !p2) return false;
    return p1->data == p2->data && f(p1->lchild, p2->rchild) && f(p1->rchild, p2->lchild);
}


bool solve(BTNode *root) {
    return f(root->lchild, root->rchild);
}

//输入为树的先序序列和后序序列
int main() {
    cout << solve(build({1, 2, 3, 4, 2, 4, 3}, {3, 2, 4, 1, 4, 2, 3})) << endl; //课本上的例子  1
    cout << solve(build({1, 3, 3, 4, 2, 4, 3}, {3, 3, 4, 1, 4, 2, 3})) << endl; //数据不对称   0
    cout << solve(build({1, 2, 4, 2, 4, 3}, {2, 4, 1, 4, 2, 3})) << endl; //节点不对称    0
}