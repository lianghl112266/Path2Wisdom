#include <bits/stdc++.h>
#include <link.h>

using namespace std;



void solve(Node *head) {
    Node *fast = head, *slow = head;
    while (fast) {
        slow = slow->next;
        fast = fast->next;
        if (fast) fast = fast->next;
    }
    
    Node *head2 = new Node();

    while (slow) {
        Node *s = slow;
        slow = slow->next;
        s->next = head2->next;
        head2->next = s;
    }

    Node *p = head->next, *q = head2->next;
    while (q) {
        if (p->val != q->val) {
            cout << "No" << '\n';
            return;
        }
        p = p->next;
        q = q->next;
    }

    cout << "Yes" << '\n';
}


int main() {
    freopen("input.txt", "r", stdin);
    int t; cin >> t; while (t--) 
    {
        int n; cin >> n;
        vector<int> a(n); for(int i = 0; i < n; i++) cin >> a[i];
        Node *head = buildByTailInsert(a);
        solve(head);
    }
}