#include <bits/stdc++.h>

using namespace std;

struct Node {
    int x;
    Node *next;
    Node(): x(0), next(nullptr) {}
    Node(int _x): x(_x), next(nullptr) {}
};

Node *build(vector<int> a) {
    sort(a.begin(), a.end());
    Node *head = new Node();
    Node *rear = head;
    for(auto x: a) {
        auto s = new Node(x);
        rear->next = s;
        rear = rear->next;
    }
    return head;
}

void solve(vector<int> a) {
    auto head = build(a);
    for(auto p = head->next; p; p = p->next) cout << p->x << " ";
    cout << '\n';
}

// 遍历链表
int main() {
    int n;
    while(cin >> n) {
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        solve(a);
    }
}
