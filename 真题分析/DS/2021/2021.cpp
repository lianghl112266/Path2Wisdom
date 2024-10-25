/*
遍历图中每一个节点， 判断是否是度为奇数的节点(后续成为奇节点)， 如果是，判断此时奇节点是否超过2（是的话退出）， 最后判断奇节点是否是2个
时间复杂度 O(n^2)
空间复杂度 O(n)

输入格式： 第一行2个数字代表顶点数和边数，剩余行代表边
输出格式： 1（true), 0(false)

测试案例
4 5
0 2
0 3
1 2
1 3
2 3
expected output: 1
*/

#include<bits/stdc++.h>
 
using namespace std;

const int MAXV = 20;

struct MGraph{
    int numVertices, numEdges;
    char VerticesList[MAXV];
    int Edge[MAXV][MAXV];
};

bool solve(MGraph g) {
    int cnt = 0;

    vector<bool> vis(g.numVertices);
    vector<int> q {0};
    vis[0] = true;

    while (!q.empty()){
        vector<int> p(q);
        q.clear();
        for(auto x: p) {
            bool odd = false;
            for (int y = 0; y < g.numVertices; y++){
                if (g.Edge[x][y]) {
                    odd = !odd;
                    if (!vis[y]) {
                        vis[y] = true;
                        q.push_back(y);
                    }
                }
            }
            cnt += odd;
            if (cnt > 2){
                return false;
            }
        }
    }
    return cnt == 2;
}
//用于输入
int main() {
    MGraph g;
    memset(g.Edge, 0, sizeof(int) * MAXV * MAXV);
    cin >> g.numVertices >> g.numEdges;
    for (int t = g.numEdges; t; t--){
        int x, y;
        cin >> x >> y;
        g.Edge[x][y] = 1;
        g.Edge[y][x] = 1;
    }
    cout << solve(g);
}