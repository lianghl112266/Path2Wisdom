/*
在拓扑排序时，判断保存度为0的节点的队列是否长度为一即可， 这里假设图联通

时间复杂度O(n * n)
空间复杂度O(n)

输入格式： 第一行2个数字代表顶点数和边数，剩余行代表边
输出格式： 1（true), 0(false)

测试用例1
3
2
0 1
1 2
expected output: 1

测试用例2
3 3
0 1
1 2
2 0
expected output: 0
*/

#include <bits/stdc++.h>

using namespace std;

const int MAXV = 10;

struct MGraph {
    int numVertices, numEdges;
    char VerticesList[MAXV];
    int Edge[MAXV][MAXV];
};

bool solve(MGraph g) {
    // 初始化度数数组
    vector<int> deg(g.numVertices);

    for (int i = 0; i < g.numVertices; i++) {
        for (int j = 0; j < g.numVertices; j++) {
            if (g.Edge[i][j]) {
                deg[j]++;
            }
        }
    }
    vector<int> q;

    for (int i = 0; i < g.numVertices; i++) {
        if (deg[i] == 0) {
            q.push_back(i);
        }
    }

    // 防止开始就是自环
    if (q.empty()) {
        return g.numVertices == 0;
    }

    // 拓扑排序
    while (!q.empty()) {
        // 如果度数为0超过1就返回false
        if (q.size() > 1) {
            return false;
        }
        vector<int> p(q);
        q.clear();
        for (auto x : p) {
            for (int y = 0; y < g.numVertices; y++) {
                if (g.Edge[x][y]) {
                    deg[y] -= 1;
                    if (deg[y] == 0) {
                        q.push_back(y);
                    }
                }

            }
        }
    }

    // 其他情况返回true
    return true;
}

// 用于输入
int main() {
    MGraph g;
    memset(g.Edge, 0, sizeof(int) * MAXV * MAXV);
    cin >> g.numVertices >> g.numEdges;
    for (int t = g.numEdges, x, y; t; t--) {
        cin >> x >> y;
        g.Edge[x][y] = 1;
    }
    cout << solve(g);
}