/*
考虑到题目给定数据范围（|x| <= n）,所以我们遍历链表的时候一边记录，
一边删除重复元素即可


时间复杂度 O(m)
空间复杂度 O(n)

输入格式:第一行两个数表示输入n个数和数据的范围, 第二行输入具体元素
输出格式：去重后的链表

测试用例

4 100
1 2 2 -2

expected output: 1 2
*/
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *next;
};

void solve(Node *head, int n) {
    vector<bool> set(n + 1);
    Node *pre = head, *cur = head->next;
    while (cur) {
        int idx = abs(cur->data);
        // 检查是否出现， 出现则删除
        if (set[idx]) {
            pre->next = cur->next;
            cur = cur->next;
        } else {
            // 没出现就标记一下， 然后继续遍历
            set[idx] = true;
            pre = cur;
            cur = cur->next;
        }
    }
}

// 用于输入
int main() {
    Node *head = new Node();
    Node *rear = head;
    int n, m;
    cin >> n >> m;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        Node *s = new Node();
        s->data = x;
        rear->next = s;
        rear = rear->next;
    }
    solve(head, m);

    for (head = head->next; head; head = head->next) {
        cout << head->data << " ";
    }
}