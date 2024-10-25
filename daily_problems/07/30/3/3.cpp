/**
 * 
 * 来自王道绿书算法章节数组第三题P104
 * 
 * 双指针遍历就行
 * 时间复杂度O(n), 空间复杂度O(1)
 * 
 * 
 * PS: 我发现王道好像很喜欢考双指针和二分， 如果对于王道没有思路， 可以从这两个反面入手， 另外， 绿书的题明显难度低于真题
 */


#include <bits/stdc++.h>

using namespace std;


int solve(vector<int> a, int k) {
    for(int i = 0, j = a.size()-1;i <= j;) {
        if (a[i]+a[j] == k) return 1;
        else if (a[i] + a[j] > k) j--;
        else i++;
    }
    return 0;
}


int main() {
    cout << solve({1, 2, 3, 7, 8, 11, 15}, 8) << endl;
    cout << solve({1, 2, 3, 7, 8, 11, 15}, 100) << endl;
}