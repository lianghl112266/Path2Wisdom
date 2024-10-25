#include <bits/stdc++.h>

using namespace std;

/**
 * 来自王道教材2.4链表小结第14题  
 * 
 *  时间复杂度O(n), 空间复杂度O(1)
 * 思路， 找到倒数第k+1个节点， 然后重组一下
 */


typedef struct node {
    int data;
    struct node *next;
    node(): data(0), next(nullptr) {}
    node(int _data): data(_data), next(nullptr){}
    node(int _data, node *_next): data(_data), next(_next){}
} *LinkList;

node *build(int n) {
    node *head = new node();
    node *rear = head; int x;
    for(int i = 0; i < n; i++) {
        cin >> x;
        rear->next = new node(x, nullptr);
        rear = rear->next;
    }
    return head;
}  

void solve(LinkList head, int k) {
    //计算长度
    int n = 0;
    for(node *p = head; p; p = p->next) n++;
    k %= n;

    //找到第n-k个节点
    int d = n - k;
    node *p = head;
    for(int i = 0; i < d - k; i++) p = p->next;

    //找到尾结点
    node *rear = p;
    while(rear->next) rear = rear->next;

    //重组指针
    rear->next = head;
    head = p->next;
    p->next = nullptr;

    for(auto p = head; p; p = p->next) cout << p->data << " ";
}


int main() {
    int n; cin >> n;
    auto head = build(n);
    head = head->next;
    solve(head, 1);
}