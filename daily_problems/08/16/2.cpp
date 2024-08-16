/**
 * 来自王道课本第6.2小结第5题
 * 时间复杂度O(n+e), 空间复杂度O(1)
 * 思路：模拟
 * 
 */

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>>  solve(vector<vector<int>> g) {
    int n = g.size();
    vector<vector<int>> ans(n, vector<int> (n));
    for(int i = 0; i < n; i++) {
        for(auto j: g[i]) {
            ans[i][j] = 1;
            //ans[j][i] = 1; 无向图做法
        }
    }
    return ans;
}