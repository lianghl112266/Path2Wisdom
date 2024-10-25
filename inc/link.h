#include <bits/stdc++.h>

struct Node {
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int _x) : val(_x), next(nullptr) {}
    Node(int _x, Node *_next) : val(_x), next(_next) {}
};

Node* buildByHeadInsert(std::vector<int> vec) {
    Node *head = new Node();
    for (const auto &val : vec) {
        head->next = new Node(val, head->next);
    }
    return head;
}

Node* buildByTailInsert(std::vector<int> vec) {
    Node *head = new Node();
    Node *rear = head;
    for (const auto &val : vec) {
        rear = rear->next = new Node(val);
    }
    return head;
}

void debugLinkList(Node *head) {
    for(Node *p = head->next; p; p = p->next) std::cout << p->val << " ";
    std::cout << '\n';
}