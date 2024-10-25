/*
先计算链表长度， 然后算逆序的k是正序的第几个，遍历过去， 然后输出

时间复杂度 O(n)
空间复杂度 O(1)

输入格式:第一行表示输入n个数和k, 第二行输入具体元素
输出格式：逆序第k个节点data

测试用例
5 1
1 2 3 4 5

expected output: 5
*/
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *next;
};

int solve(Node *head, int k) {
    int n = 0;
    // 求链表长度
    for (Node *p = head->next; p; p = p->next, n += 1) {
    }

    // 找到第正序应该是第几个节点，然后遍历
    Node *p = head;
    n = n - k + 1;
    for (int i = 0; i < n; p = p->next, i += 1) {
    }
    return p->data;
}

// 用于输入
int main() {
    int n, k, x;
    cin >> n >> k;

    Node *head = new Node();
    Node *rear = head;
    for (int i = 0; i < n; i++) {
        cin >> x;
        Node *s = new Node();
        s->data = x;
        s->next = nullptr;
        rear->next = s;
        rear = rear->next;
    }

    cout << solve(head, k);
}