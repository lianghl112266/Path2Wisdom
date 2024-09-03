#include <bits/stdc++.h>

using namespace std;


struct Node {
    int x;
    Node *next;
};


vector<Node*> solve(Node *head) {
    Node *h1 = new Node(), *h2 = new Node(), *p = head;
    Node *rear = h1;
    bool f = true;
    while(p) {
        Node *s = p;
        p = p->next;
        s->next = nullptr;
        if (f) {
            rear->next = s;
            rear = rear->next;
        }else {
            s->next = h2->next;
            h2->next = s;
        }
        f = !f;
    }
    return {h1, h2};
}


int main() {

}

