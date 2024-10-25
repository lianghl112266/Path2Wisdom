/**
 * 王道课本5.3二叉树的遍历与线索二叉树第八题
 * 时间复杂度 O(n)
 * 时间复杂度 O(logn)
 */


#include <bits/stdc++.h>

using namespace std;

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


void solve(BTNode *root) {
    function<void(BTNode*)> f = [&](BTNode *p) -> void {
        if (!p) return;
        auto a = p->lchild;
        p->lchild = p->rchild;
        p->rchild = a;
        f(p->lchild);
        f(p->rchild);
    };
    f(root);
}


int main() {
    auto root = build({1, 2, 3}, {2, 1, 3});
    solve(root);  
}