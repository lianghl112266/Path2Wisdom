#include <bits/stdc++.h>

using namespace std;


/**
 * 来自王道教材5.2二叉树的概念小结第5题  
 * 
 * 思路：  
 * 求i和j的bit串在长度相同情况下， 从上到下第一个不相同bit位，这个操作可以用异或完成
 * 然后相同bit串就是最近的祖先
 * 
 * 时间复杂度O(1), 空间复杂度O(1)  
 */

//假设下标从1开始
void solve(vector<int> a, int x, int y) {
    int xl = 31 - __builtin_clz(x);
    int yl = 31 - __builtin_clz(y);
    if (xl < yl) {
        swap(x, yl);
        swap(xl, yl);
    }
    y = y << (xl - yl);
    int i = x >> (31 - __builtin_clz(x^y) + 1);
    cout << a[i] << endl;
}

int main() {
    solve({0, 1, 2, 3, 4, 5}, 8, 5);
}