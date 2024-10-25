/*

如果存在众数， 那么一定是排序后中间位置的数，
我们可以排序后，检查中间元素出现次数是否超过一半

时间复杂度 O(nlogn)
空间复杂度 O(1)

输入格式:第一行表示输入n个数, 第二行输入具体元素
输出格式：众数（不存在输出-1）

测试用例1
7
5 5 3 5 7 5 5

expected output: 5

测试用例2
8
0 5 5 3 5 1 5 7

expected output: -1
*/
#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size(), cnt = 0;
    int ans = nums[n / 2];
    for (auto x : nums) {
        if (x == ans) {
            cnt += 1;
        }
    }
    return cnt > n / 2 ? ans : -1;
}

// 用于输入
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << solve(nums);
}