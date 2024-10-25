#include <bits/stdc++.h>

using namespace std;

/**
 * 来自王道教材2.4链表小结第15题  
 * 
 * 思路， 快慢指针， 若有环， 则两个指针必定相遇， 只需判断退出是因为快指针为空还是快慢指针相遇即可
 * 
 * 时间复杂度O(n), 空间复杂度O(1)  
 * 
 * 吐槽：  
 * 你王道在搞笑吗
 * 你让判断有没有环， 为什么你的题解是返回入口点， 你原封不动抄别人的题都抄不明白是吗
 * 附原题链接： 
 * https://leetcode.cn/problems/linked-list-cycle-ii/description/
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

bool solve(LinkList head) {
    node *fast = head->next;
    node *slow = head->next;

    if (!fast && fast->next) return false;
    fast = fast->next;

    while(fast && fast != slow) {
        fast = fast->next;
        slow = slow->next;
        if (fast) fast = fast->next;
    }

    return fast != nullptr;
}


int main() {
    int n; cin >> n;
    auto head = build(n);
    cout << solve(head);
}