#include <bits/stdc++.h>

using namespace std;


struct Node {
    int x;
    Node *left, *right;
    Node(int _x): x(_x), left(nullptr), right(nullptr) {}
};


void solve(vector<int> a) {
    int n = a.size();
    if (n == 0) return;
    
    Node *root = new Node(a[0]);
    for(int i = 1; i < n; i++) {
        auto s = root;
        while(1) {
            if (s->x == a[i]) break;
            if (s->x > a[i]) {
                if (!s->left) {
                    s->left = new Node(a[i]);
                    break;
                }
                s = s->left;
            } else {
                if (!s->right) {
                    s->right = new Node(a[i]);
                    break;
                }
                s = s->right;
            } 
        }
    }
    
    function<void(Node*, int)> f = [&](Node *o, int flag) -> void {
        if (!o) return;
        if (flag == 0) cout << o->x << " ";
        f(o->left, flag);
        if (flag == 1) cout << o->x << " ";
        f(o->right, flag);
        if (flag == 2) cout << o->x << " ";
    };

    for(int i = 0; i < 3; i++) {
        f(root, i);
        cout << endl;
    }
}


int main() {
    int n;
    while(cin >> n) {
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        solve(a);
    }
}