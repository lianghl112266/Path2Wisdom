#include <bits/stdc++.h>

using namespace std;

/**
 * 来自王道教材5.4图的应用小结第7题  
 * 
 * 
 * 思路： 模拟题
 * 
 * 时间复杂度O(n), 空间复杂度O(1)  
 */

//假设下标从1开始
void solve(vector<int> a) {
    int n = a.size();
    for(int i = n/2; i >= 0; i--) {
        int x = i*2 < n ? a[i*2] : INT_MIN;
        int y = i*2 + 1 < n ? a[i*2+1] : INT_MIN;
        if (a[i] < x || a[i] < y) {
            cout << "no" << endl;
            return;
        }
    }
    cout << "yes" << endl;
}


int main() {
    solve({0, 9, 8, 7, 6, 5, 4, 3});
    solve({0, 9, 8, 7, 6, 5, 4, 8});
}
