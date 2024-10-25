/**
 * 
 * 来自王道绿书算法章节链表第三题P108
 * 
 * 赤裸裸的改编真题2019
 * 时间复杂度O(n), 空间复杂度O(1)
 * 
 * 
 * PS: 如果看到这题想不到那真题， 那你思考是否真的认真做过真题
 */


#include <bits/stdc++.h>

using namespace std;

typedef struct node {
    int data;
    struct node *next;
} *linkList;  


bool solve(linkList head) {
    //找到中点
    node *slow = head->next, *fast = head->next;
    while(fast) {
        slow = slow->next;
        fast = fast->next;
        if (fast) fast = fast->next;
    }
    node *mid = slow;

    //翻转后半段
    node *head2 = new node();
    for(node *p = mid; p;) {
        node *s = p;
        p = p->next;
        s->next = head2->next;
        head2->next = s;
    }

    //比较
    for(node *p1 = head->next, *p2 = head2->next; p2; p1 = p1->next, p2 = p2->next) {
        if (p1->data != p2->data) return false;
    }
    return true;

}



int main() {
    node *head = new node();
    node *rear = head;
    int n;
    cin >> n;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        node *s = new node();
        s->data = x;
        rear->next = s;
        rear = rear->next;
    }
    cout << solve(head);
}