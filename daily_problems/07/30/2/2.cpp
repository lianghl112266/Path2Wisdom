/**
 * 
 * 来自王道绿书算法章节树第一题P111
 * 
 * 依次加入每个人孩子，在表上跳就行
 * 时间复杂度O(n), 空间复杂度O(log n)
 * 
 * 
 */


#include <bits/stdc++.h>

using namespace std;


typedef struct node {
    int data;
    struct node *lchild, *rchild;
    node(int _data, node *l, node *r): data(_data), lchild(l), rchild(r){}
} BTNode;



BTNode* solve(vector<int>& a) {
    function<BTNode*(int)> f = [&](int i) -> BTNode* {
        return i >= a.size() ? nullptr : new BTNode(a[i], f((i+1)*2-1), f((i+1)*2+1-1));
    };
    return f(0);
}


int main() {
    vector<int> a{10, 7, 5, 2, 6, 13, 15};
    auto p = solve(a);
}