#include <bits/stdc++.h>

using namespace std;



struct Node {
    int x;
    Node *left, *right;
    Node(): x(0), left(nullptr), right(nullptr) {}
    Node(int _x, Node *l, Node *r): x(_x), left(l), right(r){}
};

Node* build(vector<int> preOrder, vector<int> inOrder) {
        if(!preOrder.size()) return NULL;

        Node * root = new Node();
        root->x = preOrder[0];
        root->left = root->right = NULL;

        if(preOrder.size() == 1) return root;

        vector<int>::iterator it = find(inOrder.begin(), inOrder.end(), preOrder[0]);

        vector<int>pl(preOrder.begin() + 1, preOrder.begin() + 1 + (it - inOrder.begin()));
        vector<int>pr(preOrder.begin() + 1 + (it - inOrder.begin()), preOrder.end());
        vector<int>il(inOrder.begin(), it);
        vector<int>ir(it + 1, inOrder.end());

        root->left = build(pl, il);
        root->right = build(pr, ir);

        return root;
}


void solve(Node *root) {
    function<int(Node*, int)> f = [&](Node *p, int mx) -> int {
        if (!p) return 0;
        return f(p->left, max(mx, p->x)) + f(p->right, max(mx, p->x)) + (p->x >= mx);
    };
    cout << f(root, 0);
}


// 复旦大学 复旦2021
int main() {
    vector<int> pre{3, 1, 7, 4, 2, 5}, in {7, 1, 3, 2, 4, 5};
    auto root = build(pre, in);
    solve(root);
}