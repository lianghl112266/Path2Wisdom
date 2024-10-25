/*

先找到中间节点， 然后反转后半段链表， 然后重排就行


时间复杂度 O(n)
空间复杂度 O(1)

输入格式: 第一行代表链表节点个数， 第二行是节点值
输出格式：重排后链表data域

测试用例1
4
1 2 3 4
expected output: 1 4 2 3

测试用例1
5
1 2 3 4 5
expected output: 1 5 2 4 3
*/
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int weight;
    Node *next;
};

void solve(Node *head) {
    // 如果链为空或者只有一个节点直接返回，保证逻辑正确的同时，
    // 下面代码不会空指针错误
    if (!head->next || !head->next->next) {
        return;
    }

    // 找到中点节点，利用快慢指针，快指针每次两步，慢指针一步， 快指针到终点时，
    // 慢指针就是中点

    Node *fast = head->next, *slow = head->next;
    while (fast) {
        slow = slow->next;
        fast = fast->next;
        if (fast) {
            fast = fast->next;
        }
    }
    Node *mid = slow;

    // 反转后面链表
    Node *head2 = new Node();
    while (mid) {
        Node *s = mid;
        mid = mid->next;
        s->next = head2->next;
        head2->next = s;
    }

    // 重排，把后面的链穿插在前面的链，这里用尾指针保证最后一个节点的next为nullptr
    Node *p = head2->next, *q = head->next;
    Node *rear = q;
    while (p) {
        Node *s = p;
        p = p->next;
        s->next = q->next;
        q->next = s;
        q = q->next->next;
        rear = q;
    }
    rear->next = nullptr;
}

// 用于输入
int main() {
    Node *head = new Node();
    Node *rear = head;
    int n;
    cin >> n;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        Node *s = new Node();
        s->weight = x;
        rear->next = s;
        rear = rear->next;
    }
    solve(head);

    for (head = head->next; head; head = head->next) {
        cout << head->weight << " ";
    }
}