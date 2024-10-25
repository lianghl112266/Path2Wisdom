/**
 * 
 * 来自王道绿书P104算法章节数组第五题
 * 
 */



#include <bits/stdc++.h>

using namespace std;


//#define TREE
//#define GRAPH_ADJMAT

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

/**
 * 我惊了， 第一次看见王道出这种题，真题都没考过
 * 
 * 后缀数组
 * 保存每个数右边的最小值， 然后从左到右遍历
 * 
 * 时间复杂度O(n), 空间复杂度O(n)
 */


void solve(vector<int> a) {
    int n = a.size();
    vector<int> b(n);
    b[n-1] = a[n-1];
    for(int i = n - 2; i >= 0; i--) b[i] = min(b[i+1], a[i+1]);
    int ans = INT_MIN;
    for(int i = 0; i < n-1; i++) ans = max(ans, a[i]-b[i]);
    cout << ans << endl;
}


/**
 * 
 * 第一眼， 单调栈， 第二眼， 后缀数组， 第三眼， 可以优化， hhhh， 大意了
 * 毕竟再王道算法中， 同一解法可优化我还是第一次见到，就没多想， 用一个变量代替b数组就行了
 * 
 * 时间复杂度O(n), 空间复杂度O(1)
 * 
 */

void solve1(vector<int> a) {
    int n = a.size();
    int b = a[n-1];
    int ans = INT_MIN;
    for(int i = n-2; i >= 0; i--) {
        ans = max(ans, a[i]-b);
        b = min(a[i], b);
    }
    cout << ans << endl;
}

/**
 * 
 * 第四眼, 写完发现王道是正向遍历哈哈哈哈， 算了， 懒得写了， 感觉差不多， 我的也是对的
 * 
 * 时间复杂度O(n), 空间复杂度O(1)
 * 
 */

int main() {
    solve({2, 4, 1, 16, 7, 5, 11, 9});
    solve1({2, 4, 1, 16, 7, 5, 11, 9});
}