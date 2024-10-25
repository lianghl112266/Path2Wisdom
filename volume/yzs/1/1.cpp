#include <bits/stdc++.h>
#include <link.h>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    int n; cin >> n;
    vector<int> a(n); for(int i = 0; i < n; i++) cin >> a[i];
    Node *head = buildByTailInsert(a);

    // solve
    Node *pre = head, *head2 = new Node();
    Node *p = head->next;
    for(bool retain = true; p; retain = !retain) {
        if (retain) {
            pre = pre->next;
            p = p->next;
        } else {
            Node *s = p;
            p = p->next;
            pre->next = p;
            s->next = head2->next;
            head2->next = s;
        }
    }

    debugLinkList(head);
    debugLinkList(head2);
}