/**
 * 
 * 来自王道绿书P104算法章节数组第二题
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
 * 双指针模拟
 * 
 * 时间复杂度O(n+m), 空间复杂度O(1)
 */


void solve(vector<int> a, vector<int> b) {
    int n = a.size(), m = b.size();
    int mi_d = INT_MAX;
    vector<pair<int, int>> ans;
    for(int i = 0, j = 0; i < n || j < m;) {
        int x = i < n ? a[i] : a[n-1];
        int y = j < m ? b[j] : b[n-1];
        int d = abs(x-y);
        if (d == mi_d) ans.push_back({x, y});

        if (d < mi_d) {
            ans.clear();
            ans.push_back({x, y});
            mi_d = d;
        }
        
        if (j == m || x <= y) i++;
        else j++;
    }
    for (auto [x, y]: ans) cout << x << " " << y << '\n';
}

int main() {
    solve({-16, -8, 5, 8, 13}, {-2, 0, 2, 6, 10});
}