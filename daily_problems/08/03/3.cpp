/**
 * 
 * 来自王道绿书P108算法章节链表第二题
 * 
 */



#include <bits/stdc++.h>

using namespace std;


//#define TREE
//#define GRAPH_ADJMAT
#define LINKLIST

#ifdef TREE
typedef struct node {
    int data;
    struct node *lchild, *rchild;
    node(): data(0), lchild(nullptr), rchild(nullptr) {}
    node(int _data, node *l, node *r): data(_data), lchild(l), rchild(r){}
} BTNode;
#endif

#ifdef GRAPH_ADJMAT
const int MAXV = 100;
typedef struct {
    int numV, numE;
    char VerticesList[MAXV];
    int Edge[MAXV][MAXV];
} MGraph;
#endif

#ifdef LINKLIST
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
        rear->next = new node(x);
        rear = rear->next;
    }
    return head;
}
#endif

/**
 * 
 * 双指针模拟
 * 
 * 
 * 时间复杂度O(n+m), 空间复杂度O(1)
 */


node* solve(node *head1, node *head2) {
    node *head = new node();
    node *rear = head;
    for(node *p = head1->next, *q = head2->next; p && q;) {
        if (p->data == q->data) {
            rear->next = new node(p->data);
            rear = rear->next;
            p = p->next;
            q = q->next;
        }else if (p->data < q->data) p = p->next;
        else q = q->next;
    }
    return head;
}

int main() {
    auto l1 = build(3);
    auto l2 = build(4);
    auto a = solve(l1, l2);
    for(auto p = a->next; p; p = p->next) cout << p->data << " ";
}