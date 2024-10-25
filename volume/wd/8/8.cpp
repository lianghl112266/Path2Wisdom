#include <bits/stdc++.h>
#include <link.h>

using namespace std;


int main() {
    freopen("input.txt", "r", stdin);
    int t; cin >> t;
    while(t--) {
        // 尾插建立链表
        int n; cin >> n;
        vector<int> a(n); for(int i = 0; i < n; i++) cin >> a[i];
        Node *head = buildByTailInsert(a);

        //slove
        
        //找到中间节点
        Node *fast = head, *slow = head;
        while(fast) {
            slow = slow->next;
            fast = fast->next;
            if (fast) fast = fast->next;
        }
        Node *mid = slow;
        
        //翻转后半链
        Node *head2 = new Node(), *p = mid->next;
        while (p) {
            Node *s = p;
            p = p->next;
            s->next = head2->next;
            head2->next = s;
        }

        //判相等
        Node *p1 = head->next, *p2 = head2->next; 
        while(p2 && p1->val == p2->val) {
            p1 = p1->next;
            p2 = p2->next;
        }

        cout << (p2 ? "No" : "Yes") << '\n';
    }

}