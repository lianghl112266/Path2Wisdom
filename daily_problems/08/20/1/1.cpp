#include <bits/stdc++.h>

using namespace std;

struct Node {
    char c;
    Node *left, *right;
    Node(char _c): c(_c), left(nullptr), right(nullptr) {}
};

Node *solve(string s) {
    int n = s.size();
    int i = 0;
    function<Node*()> f = [&]() -> Node* {
        if (i >= n || s[i] == '#') {
            i++;
            return nullptr;
        }
        Node *a = new Node(s[i++]);
        a->left = f();
        a->right = f();
        return a;
    };

    return f();
}

void pt(Node *o) {
    if (!o) return;
    pt(o->left);
    cout << o->c << " ";
    pt(o->right);
}

int main() {
    string s; cin >> s;
    pt(solve(s));
}