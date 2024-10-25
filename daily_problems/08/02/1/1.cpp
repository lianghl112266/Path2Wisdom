/**
 * 
 * 来自王道绿书P104算法章节数组第四题
 * 
 * 
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
 * 
 * 排序+二分
 * 
 * 时间复杂度O(n*logn), 空间复杂度O(logn)
 */


int solve(vector<int> a, int k) {

    sort(a.begin(), a.end());

    int n = a.size();
    auto bisect = [&](int t) -> int {
        int i = 0, j = n - 1;
        while(i <= j) {
            int mid = (i+j)/2;
            if (a[mid] < t) i = mid + 1;
            else j = mid - 1;
        }
        return i;
    };

    int mx = 0;
    for (int i = 0; i < n; i++) {
        int x = bisect(a[i]-k);
        mx = max(mx, i-x+1);
    }

    return mx;
}

/**
 * 
 * 计数+滑动窗口
 * 
 * 时间复杂度O(n), 空间复杂度O(n)
 */


int solve1(vector<int> a, int k) {
    int n = a.size();
    vector<int> b(n);
    for(auto x: a) b[x]++;
    
    int i = 0, j = 0, mx = 0, cur = 0;
    while(j < n) {
        while(j - i > k) cur -= b[i++];
        cur += b[j++];
        mx = max(mx, cur);
    }

    return mx;
}


int main() {
    cout << solve({1, 4, 3, 3, 2, 2, 3}, 2) << endl;
    cout <<solve1({1, 4, 3, 3, 2, 2, 3}, 2) << endl;
}