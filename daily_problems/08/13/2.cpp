#include <bits/stdc++.h>

using namespace std;


/**
 * 来自王道教材2.2线性表的顺序表示找小结第6题  
 * 
 * 思路：  
 * 双指针模拟
 * 
 * 时间复杂度O(m+n), 空间复杂度O(1)  
 */

void solve(vector<int> a, vector<int> b) {
    int n = a.size(), m = b.size();
    int ans[n+m] = {0};
    for(int i = 0, j = 0, k = 0; i < n || j < m; k++) {
        int x = i == n ? INT_MAX : a[i];
        int y = j == m ? INT_MAX : b[j];
        ans[k] = min(x, y);
        if (j == m || x < y) i++;
        else j++;
    }
    for(auto x: ans) cout << x  << " ";
}


int main() {
    solve({3, 6, 9}, {1, 5, 8, 10});
}