/**
 * 双指针遍历即可
 * 时间复杂度O(n+m)
 * 空间复杂度O(1)
 * 
 * 
 * 输入实例：第一行为A和B链长度， 第二行和第三行分别为AB链数据
 * 4 3
 * 2 0 4 3 -1 6 5 7
 * 1 3 2 7 -2 8
 * 
 * 输出：
 * 2 0
 * 5 3
 * -11 6
 * 7 7
 * -2 8
 */


#include <bits/stdc++.h>

using namespace std;


struct Node {
    float co;
    int ex;
    Node *next;
    Node():co(0),ex(0),next(nullptr){}
    Node(float _co, int _ex) :co(_co),ex(_ex),next(nullptr){}
    Node(float _co, int _ex, Node *_next) :co(_co),ex(_ex),next(_next){}
} *Polynomial;


Node *solve(Node *A, Node *B) {
    Node *head = new Node();
    Node *rear = head, *p = A->next, *q = B->next;
    while (p || q) {
        int x_co = p ? p->co : 0;
        int x_ex = p ? p->ex : INT_MAX;
        int y_co = q ? q->co : 0;
        int y_ex = q ? q->ex : INT_MAX;

        if (x_ex < y_ex) {
            p = p->next;
            Node *s = new Node(x_co, x_ex);
            rear->next = s;
            rear = s;
        }else if (y_ex < x_ex) {
            q = q->next;
            Node *s = new Node(y_co, y_ex);
            rear->next = s;
            rear = s;
        }else {
            p = p->next;
            q = q->next;
            Node *s = new Node(y_co + x_co, y_ex);
            rear->next = s;
            rear = s;
        }
    }
    return head;
}

Node *build(int n) {
    Node *head = new Node();
    Node *rear = head; float co; int ex;
    for(int i = 0; i < n; i++) {
        cin >> co >> ex;
        Node *s = new Node(co, ex);
        rear->next = s;
        rear = s;
    }
    return head;
}

int main() {
    int n, m;
    cin >> n >> m;
    Node *ans = solve(build(m), build(n));
    for(Node *p = ans->next; p; p = p->next) cout << p->co << " " << p->ex << endl;
}