#include <bits/stdc++.h>

struct Node {
    int val;
    Node *left, *right;
    Node(): val(0), left(nullptr), right(nullptr) {}
    Node(int _x, Node *l, Node *r): val(_x), left(l), right(r){}
};

Node* build(std::vector<int> preOrder, std::vector<int> inOrder) {
        if(!preOrder.size()) return NULL;

        Node * root = new Node();
        root->val = preOrder[0];
        root->left = root->right = NULL;

        if(preOrder.size() == 1) return root;

        std::vector<int>::iterator it = find(inOrder.begin(), inOrder.end(), preOrder[0]);

        std::vector<int>pl(preOrder.begin() + 1, preOrder.begin() + 1 + (it - inOrder.begin()));
        std::vector<int>pr(preOrder.begin() + 1 + (it - inOrder.begin()), preOrder.end());
        std::vector<int>il(inOrder.begin(), it);
        std::vector<int>ir(it + 1, inOrder.end());

        root->left = build(pl, il);
        root->right = build(pr, ir);

        return root;
}
