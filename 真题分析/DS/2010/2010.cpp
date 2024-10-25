/*
先反转全部数字， 再反转前p个数字， 再反转后n-p个数字

时间复杂度 O(n)
空间复杂度 O(1)

输入格式:第一行表示输入n个数和p, 第二行输入具体元素
输出格式：左移后的数组

测试用例
5 2
1 2 3 4 5

expected output: 4 5 1 2 3
*/
#include <bits/stdc++.h>

using namespace std;

void solve(vector<int> &nums, int p) {
    //反转[i, j)个元素的函数
    auto rsv = [&](int i, int j) {
        for (int k = 0, n = (j - i) / 2; k < n; k++) {
            swap(nums[i + k], nums[j - 1 - k]);
        }
    };
    int n = nums.size();
    //三次反转
    rsv(0, n);
    rsv(0, p);
    rsv(p, n);
}
// 用于输入
int main() {
    int n, p;
    cin >> n >> p;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    solve(nums, p);
    for(auto x: nums) cout << x << ' '; cout << endl;
}