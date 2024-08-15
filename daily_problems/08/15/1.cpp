/**
 * 来自王道课本第5.3小结第6题
 * 时间复杂度O(n), 空间复杂度O(logn)
 * 思路： DFS
 * 判断节点个数是否等于按照完全二叉树编号的最大节点编号
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

bool solve(BTNode *root) {
    int cnt = 0, mx_idx = 0;
    function<void(BTNode*, int)> f = [&](BTNode *p, int k) -> void {
        if (!p) return;
        mx_idx = max(mx_idx, k);
        cnt++;
        f(p->lchild, k * 2);
        f(p->rchild, k * 2 + 1);
    };
    f(root, 1);
    
    return cnt == mx_idx;
}


int main() {
    cout << solve(build({1, 2, 4, 5, 3, 6}, {4, 2, 5, 1, 6, 3})) << '\n'; // 1
    cout << solve(build({1, 2, 5, 3, 6}, {2, 5, 1, 6, 3})) << '\n'; //0
}