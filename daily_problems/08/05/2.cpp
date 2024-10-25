/**
 * 来自王道课本P360第2题
 */

#include <bits/stdc++.h>

using namespace std;


//#define TREE
//#define GRAPH_ADJMAT
//#define LINKLIST
#ifdef TREE
typedef struct node {
    int data;
    struct node *lchild, *rchild;
    node(): data(0), lchild(nullptr), rchild(nullptr) {}
    node(int _data, node *l, node *r): data(_data), lchild(l), rchild(r){}
} BTNode;

BTNode* build(vector<int> preOrder, vector<int> inOrder) {
        if(!preOrder.size()) return NULL;

        BTNode * root = new BTNode();
        root->data = preOrder[0];
        root->lchild = root->rchild = NULL;

        if(preOrder.size() == 1) return root;

        vector<int>::iterator it = find(inOrder.begin(), inOrder.end(), preOrder[0]);

        vector<int>pl(preOrder.begin() + 1, preOrder.begin() + 1 + (it - inOrder.begin()));
        vector<int>pr(preOrder.begin() + 1 + (it - inOrder.begin()), preOrder.end());
        vector<int>il(inOrder.begin(), it);
        vector<int>ir(it + 1, inOrder.end());

        root->lchild = build(pl, il);
        root->rchild = build(pr, ir);

        return root;
}

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
 * 快排中轴是第k个元素时退出
 * 
 * 时间复杂度O(n), 空间复杂度O(logn)
 */

int f(vector<int>& a, int i , int j) {
    int x = a[i];
    while(i < j) {
        while(i < j && a[j] >= x) j--;
        if (i < j) a[i] = a[j];
        while(i < j && a[i] <= x) i++;
        if (i < j) a[j] = a[i];
    }
    a[i] = x;
    return i;
}


int solve(vector<int>& a, int i, int j, int k) {
    k--;
    if (i < j) {
        int mid = f(a, i, j);
        if (mid == k) return a[k];
        solve(a, i, mid-1, k);
        solve(a, mid+1, j, k);
    }
    return a[k];
}


int main() {
    vector<int> a{9,8,7,6,5,4,3,2,1};
    int k = 3;
    cout << solve(a, 0, a.size()-1, k);
}