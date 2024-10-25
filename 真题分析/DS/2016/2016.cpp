/*
因为要求分开后长度差最小， 所以策略就是对半分，又因为要两边和的差最大，
所以把最小的一半放在一堆， 最大一半放在一推， 根据思路，我们只需要找到中枢
即可， 可以采用快排思想


时间复杂度 O(n)
空间复杂度 O(1)

输入格式:第一行表示输入n个数, 第二行输入具体元素
输出格式：最小的差

测试案例1
6
4 5 3 2 6 1

expected output: 9

测试案例2
6
5 4 3 6 1 2

expected output: 9
*/

#include <bits/stdc++.h>

using namespace std;

int f(vector<int>& nums, int i, int j) {
    int x = nums[i];
    while (i < j) {
        while (i < j && nums[j] >= x) j--;
        nums[i] = nums[j];
        while (i < j && nums[i] <= x) i++;
        nums[j] = nums[i];
    }
    nums[i] = x;
    return i;
}

// 快排模板
void quickSort(vector<int>& nums, int i, int j) {
    if (i < j) {
        int mid = f(nums, i, j);
        // 当是中轴位置时退出
        if (mid == nums.size() / 2) {
            return;
        }
        quickSort(nums, i, mid - 1);
        quickSort(nums, mid + 1, j);
    }
}

int solve(vector<int>& nums) {
    int n = nums.size(), s1 = 0, s2 = 0;
    if (n == 0) {
        return 0;
    }
    quickSort(nums, 0, n - 1);
    // 两堆数组分别求和
    for (int i = 0, k = n / 2; i < k; i++) {
        s1 += nums[i];
        s2 += nums[n - 1 - i];
    }

    // 当时奇数个元素时，判断以下中间元素应该放在那一堆
    if ((n & 1) == 1) {
        return max(abs(s1 - s2 + nums[n / 2]), abs(s2 - s1 + nums[n / 2]));
    }
    return s2 - s1;
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