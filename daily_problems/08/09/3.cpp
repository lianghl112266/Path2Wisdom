/**
 * 来自王道课本第5.3小结第10题
 * 时间复杂度O(n), 空间复杂度O(logn)
 * 思路： 发现孩子是x时， 就删除
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

void solve(BTNode *root, int x) {
    function<void(BTNode*)> f = [&](BTNode *p) -> void {
        if (p->lchild) {
            if (p->lchild->data == x) {
                auto s = p->lchild;
                p->lchild = nullptr;
                free(s);
                return;
            }
            f(p->lchild);
        }
        if (p->rchild) {
            if (p->rchild->data == x) {
                auto s = p->rchild;
                p->rchild = nullptr;
                free(s);
                return;
            }
            f(p->rchild);
        }
    };
    f(root);
    
}


int main() {
    auto root = build({1, 2, 3, 4, 5, 6}, {2, 3, 1,5,6,4});
    solve(root, 2);
}