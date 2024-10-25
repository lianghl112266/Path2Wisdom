#include <bits/stdc++.h>
#include <tree.h>

using namespace std;


void dfs(vector<Node*> arr) {
    int n = arr.size();
    if (n == 0) return ;
    vector<Node*> ch;
    for(int i = 0; i < n; i++) {
        if (arr[i]->right) ch.push_back(arr[i]->right);
        if (arr[i]->left) ch.push_back(arr[i]->left);
    }
    dfs(ch);
    for(int i = 0; i < n; i++) cout << arr[i]->val << ' ';
    cout << '\n';
}


int main() {
    freopen("input.txt", "r", stdin);
    int n; cin >> n;
    vector<int> pre(n); for(int i = 0; i < n; i++) cin >> pre[i];
    vector<int> in(n); for(int i = 0; i < n; i++) cin >> in[i];
    Node *root = build(pre, in);
    if (root) dfs({root});
}