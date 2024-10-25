/**
 * 来自王道课本第5.3小结第4题
 * 时间复杂度O(n), 空间复杂度O(n)
 * 思路： BFS
 * 
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
    if (!root) return;
    vector<BTNode*> q {root};
    while (!q.empty()) {
        vector<BTNode*> p(q);
        q.clear();
        for(auto x: p) {
            cout << x->data << " ";
            if (x->rchild) q.push_back(x->rchild);
            if (x->lchild) q.push_back(x->lchild);
        }
    }
}


int main() {
    solve(build({1, 2, 4, 5, 3, 6}, {4, 2, 5, 1, 6, 3}));
}