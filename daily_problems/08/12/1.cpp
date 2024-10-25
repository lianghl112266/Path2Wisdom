#include <bits/stdc++.h>

using namespace std;


/**
 * 来自王道教材7.2顺序查找和折半查找小结第6题  
 * 
 * 思路：  
 * 聪明的做法是从右上角元素开始遍历
 * 
 * 时间复杂度O(m+n), 空间复杂度O(1)  
 */

void solve(vector<vector<int>> a, int k) {
    int n = a.size(), m = a[0].size();
    int i = n-1, j = 0;
    bool find = false;
    while(i >= 0 && j < m) {
        if (a[i][j] == k) {
            find = true;
            break;
        }
        if (a[i][j] > k) i--;
        else j++;
    }
    cout << (find ? "yes" : "QAQ no!") << endl; 
}


int main() {
    solve({{1, 4, 7}, {2, 5, 8}, {3, 6, 9}}, 5);
}