/*
递归的加括号就行了，注意根节点和叶节点不用加

时间复杂度 O(n)
空间复杂度 O(n)


输出格式：(a+b)*(c*(-d))
*/
#include <bits/stdc++.h>

using namespace std;

struct Node {
    string data;
    Node *left, *right;
};

string solve(Node *root) {
    function<string(Node *, int)> dfs = [&](Node *o, int level) -> string {
        // 空节点直接返回就行
        if (!o) {
            return "";
        }
        // 叶子节点不加括号
        if (o->left == o->right) {
            return o->data;
        }
        // 普通非根节点加括号
        if (level != 0) {
            return "(" + dfs(o->left, level + 1) + o->data +
                   dfs(o->right, level + 1) + ")";
        }
        // 根节点加括号
        return dfs(o->left, level + 1) + o->data + dfs(o->right, level + 1);
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
    root->data = "*";
    root->left->data = "+";
    root->right->data = "*";
    root->left->left->data = "a";
    root->left->right->data = "b";
    root->right->left->data = "c";
    root->right->right->data = "-";
    root->right->right->right->data = "d";

    cout << solve(root);
}