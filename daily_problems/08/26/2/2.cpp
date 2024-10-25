#include <bits/stdc++.h>

using namespace std;


const int inf = 0x3f3f3f3f;

struct Node {
    int x;
    Node *next;
    Node(): x(0), next(nullptr) {}
    Node(int _x): x(_x), next(nullptr) {}
    Node(int _x, Node *_next): x(_x), next(_next) {}
};


Node *build(int n) {
    auto head = new Node();
    auto rear = head;
    while(n--) {
        auto s = new Node();
        cin >> s->x;
        rear->next = s;
        rear = s;
    }
    return head;
}


void solve(Node *h1, Node *h2) {
    auto p1 = h1->next, p2 = h2->next, head = new Node();
    while(p1 || p2) {
        int x = p1 ? p1->x : inf;
        int y = p2 ? p2->x : inf;
        if (x < y) {
            p1 = p1->next;
            head->next = new Node(x, head->next);
        } else {
            p2 = p2->next;
            head->next = new Node(y, head->next);
        }
    }
    for(auto p = head->next; p; p = p->next) cout << p->x << ' ';
}


int main() {
    int n, m; cin >> n >> m;
    auto h1 = build(n), h2 = build(m);
    solve(h1, h2);
}