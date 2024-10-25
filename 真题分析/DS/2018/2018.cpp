/*
我们对数组进行遍历，对于遍历到的数，如果它在 [1,n]的范围内，那么就将数组中
的第 x−1 个位置打上负数标记。在遍历结束之后，如果所有的位置都被打上了标记，
那么答案是n+1，否则答案是最小的没有打上标记的位置加 1

时间复杂度 O(n)
空间复杂度 O(1)

输入格式: 第一行代表数的个数， 第二行是数值
输出格式：计算结果

测试用例1
4
-5 3 2 3
expected output: 1

测试用例1
3
1 2 3
expected output: 4
*/
#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> nums) {
    int n = nums.size();
    // 先把所有负数都变成正数，保证数组没有负数
    for (int& num : nums) {
        if (num <= 0) {
            num = n + 1;
        }
    }

    // 如果是0-n（开区间）内的正数，就把相应位置的数变为负
    for (int i = 0; i < n; i++) {
        int num = abs(nums[i]);
        if (num <= n) {
            nums[num - 1] = -abs(nums[num - 1]);
        }
    }

    // 第一个正数位置记录的位置， 就是缺失的正数-1
    for (int i = 0; i < n; i++) {
        if (nums[i] > 0) {
            return i + 1;
        }
    }

    // 缺失的第一个数是n
    return n + 1;
}
// 用于输入
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        nums[i] = x;
    }
    cout << solve(nums);
}