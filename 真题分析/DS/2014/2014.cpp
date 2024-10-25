/*

时间复杂度 O(n)
空间复杂度 O(n)


输出格式：
*/
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int weight;
    Node *left, *right;
};

int solve(Node *root) {
    function<int(Node *, int)> dfs = [&](Node *o, int level) -> int {
        if (!o) {
            return 0;
        }
        return o->left == o->right
                   ? o->weight * level
                   : dfs(o->left, level + 1) + dfs(o->right, level + 1);
    };
    return dfs(root, 0);
}

// 用于输入
int main() {
    Node *root = new Node();
    root->left = new Node();
    root->right = new Node();
    root->left->left = new Node();
    root->left->right = new Node();
    root->right->left = new Node();
    root->right->right = new Node();
    root->right->right->right = new Node();
    root->weight = 1;
    root->left->weight = 2;
    root->right->weight = 3;
    root->left->left->weight = 4;
    root->left->right->weight = 5;
    root->right->left->weight = 6;
    root->right->right->weight = 7;
    root->right->right->right->weight = 8;

    cout << solve(root);
}