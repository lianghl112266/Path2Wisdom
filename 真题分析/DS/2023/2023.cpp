/*
遍历即可， 统计节点的出度减入度， 大于0时，计入答案
时间复杂度 O(n^2)
空间复杂度 O(1)
*/
#include<bits/stdc++.h>
 
using namespace std;

const int MAXV = 10;

struct MGraph {
    int numVertices, numEdges;
    char VerticesList[MAXV];
    int Edge[MAXV][MAXV];
};

int solve(MGraph *g) {
    int n = g->numVertices;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int cnt = 0;
        for(int k = 0; k < n; k++) {
            if (g->Edge[i][k] == 1) cnt++;
            if (g->Edge[k][i] == 1) cnt--;
        }
        if (cnt > 0) {
            cout << g->VerticesList[i] << '\n';
            ans += 1;
        }
    }
    return ans;
}