/*

双指针问题， 每次移动小数所在数组的指针， 移动直到找到中间元素后停止

时间复杂度 O(n+m)
空间复杂度 O(1)

输入格式:第一行是两个数组长度, 第二行为第一个数组元素， 第三行为第二个数组元素
输出格式：中轴元素

测试用例1
5 5
11 13 15 17 19
2 4 6 8 20

expected output: 11
测试用例2
5 0
11 13 15 17 19

expected output: 15

*/
#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> nums1, vector<int> nums2) {
    int n = nums1.size(), m = nums2.size(), ans = 0;
    // 中轴元素位置mid
    int mid = (n + m + 1) / 2 - 1;
    if (n == 0) {
        return nums2[mid];
    }
    if (m == 0) {
        return nums1[mid];
    }

    // 每次移动小数字指针
    for (int i = 0, j = 0; i + j <= mid;) {
        int x = i < n ? nums1[i] : nums1[n - 1];
        int y = j < m ? nums2[j] : nums2[m - 1];
        // 移动时记录答案即可
        ans = min(x, y);
        if (j == m || x <= y) {
            i += 1;
        } else if (i == n || y <= x) {
            j += 1;
        }
    }
    return ans;
}

// 用于输入
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums1(n);
    vector<int> nums2(m);
    for (int i = 0; i < n; i++) {
        cin >> nums1[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> nums2[i];
    }
    cout << solve(nums1, nums2);
}