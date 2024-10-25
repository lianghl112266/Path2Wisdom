/**
 * 广度优先搜索即可， 每拿到一层节点就判断是不是最多的
 * 时间复杂度O(n), 空间复杂度O(n)
 * 
 */


#include <bits/stdc++.h>

using namespace std;

struct Node {
    char data;
    Node *left, *right;
};

void solve(Node *root) {
    if (!root) {
        cout << 0;
        return;
    }
    int ans = 0;
    vector<Node*> q {root};
    while(!q.empty()) {
        ans = max(ans, (int)q.size());
        vector<Node*> p(q);
        q.clear();
        for (auto x: p) {
            if (x->left) q.emplace_back(x->left);
            if (x->right) q.emplace_back(x->right);
        }
    }
    cout << ans;
}



int main() {
    Node *root = new Node();
    root->left = new Node();
    root->right = new Node();
    root->right->left = new Node();
    solve(root);
}