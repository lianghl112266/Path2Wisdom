#include <bits/stdc++.h>

using namespace std;

/**
 * 王道课本8.4选择排序第五题
 * 按照过程模拟就行，注意用p->next->data比p->data好写
 * 时间复杂度 O(n^2)
 * 时间复杂度 O(1)
 */

typedef struct node {
    int data;
    struct node *next;
    node() : data(0), next(nullptr) {}
    node(int _data) : data(_data), next(nullptr) {}
    node(int _data, node *_next) : data(_data), next(_next) {}
} *LinkList;

node *build(int n) {
    node *head = new node();
    node *rear = head;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        rear->next = new node(x, nullptr);
        rear = rear->next;
    }
    return head;
}

void debugLink(node *head) {
    for (auto p = head->next; p; p = p->next) cout << p->data << " ";
}

void solve(LinkList head) {
    for (auto p = head; p->next; p = p->next) {
        auto s = p;
        for (auto q = p->next; q->next; q = q->next) {
            if (q->next->data < s->next->data) s = q;
        }
        if (s != p) {
            auto a = s->next;
            auto b = p->next;

            if (p->next == s) {
                s->next =a->next;
                a->next = s;
                p->next = a;
            } else {
                s->next = a->next;
                p->next = b->next;

                b->next = s->next;
                s->next = b;
                a->next = p->next;
                p->next = a;
            }
        }
    }
    debugLink(head);
}

int main() {
    int n;
    cin >> n;
    auto head = build(n);
    solve(head);
}