/*

让长链（n）从和短链(m)长度相同节点处出发， 这样两个链表一起遍历时，
如果有公共节点,就能及时发现


时间复杂度 O(n+m)
空间复杂度 O(1)

输入格式: 第一行两个数代表链A长度和链B在A的挂载点，第二行是链A的数据
输出格式：公共节点的data

测试用例
5 3
1 2 3 4 5

expected output: 3
*/
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *solve(Node *head1, Node *head2) {
    // 求链的长度
    int n = 0, m = 0;
    for (Node *p = head1; p; p = p->next, n++) {
    }
    for (Node *p = head2; p; p = p->next, m++) {
    }
    // 始终让n为长链长度， head1指向长链
    if (m > n) {
        {
            Node *tmp = head1;
            head1 = head2;
            head2 = tmp;
        }
        {
            int tmp = n;
            n = m;
            m = tmp;
        }
    }

    // 让长链（n）从和短链(m)长度相同节点处出发
    for (int k = n - m; k; head1 = head1->next, k--) {
    }

    // 一起遍历
    for (Node *p = head1->next, *q = head2->next; p; p = p->next, q = q->next) {
        if (p == q) return p;
    }
    return nullptr;
}

// 用于输入
int main() {
    int n, m, x;
    cin >> n >> m;
    if (m > n) {
        return;
    }

    Node *head1 = new Node();
    Node *rear = head1;
    for (int i = 0; i < n; i++) {
        cin >> x;
        Node *s = new Node();
        s->data = x;
        rear->next = s;
        rear = rear->next;
    }

    Node *head2 = new Node(), *p = head1;
    rear = head2;
    for (int i = 0; i < m; i++) {
        Node *s = new Node();
        rear->next = s;
        rear = rear->next;
        p = p->next;
    }
    rear->next = p;

    cout << solve(head1, head2)->data;
}