/*
三指针问题， 由于都是单调递增，每次移动一个指针判断一下是不是最小的间隔， 每次移动指向最小的元素的指针


时间复杂度 O(n)
空间复杂度 O(1)

输入格式： 第一行3个数字表示三个向量长度， 接下来三行分别是三个向量里的数字
输出格式： 一个数字
测试案例
3 4 5
-1 0 9
-25 -10 10 11
2 9 17 30 41

expected output: 2
*/
#include<bits/stdc++.h>
 
using namespace std;


int solve(vector<int> nums1, vector<int> nums2, vector<int> nums3) {
    //方便编码吧， 可以不用这么写
    vector<vector<int>> nums{nums1, nums2, nums3};
    //向量长度和指针
    int n1 = nums1.size(), n2 = nums2.size(), n3 = nums3.size();
    int i = 0, j = 0, k = 0, ans = INT32_MAX;

    while(i < n1 || j < n2 || k < n3) {
        int x = i < n1 ? nums[0][i] : nums[0][n1 - 1];
        int y = j < n2 ? nums[1][j] : nums[1][n1 - 1];
        int z = k < n3 ? nums[2][k] : nums[2][n1 - 1];
        //判断是否是最小
        ans = min(ans, abs(x - y) + abs(y - z) + abs(z - x));
        //移动指针
        if (i < n1 && (j == n2 || x <= y) && (k == n3 || x <= z)){
            i += 1;
        }else if (j < n2 && (i == n1 || y <= x) && (k == n3 || y <= z)){
            j += 1;
        }else if (k <= n3 && (i == n1 || z <= x) && (j == n2) || z <= y){
            k += 1;
        }
    }
    return ans;
}

//用于输入
int main() {
    int n, m, k, x;
    cin >> n >> m >> k;
    vector<int> nums1;
    while (n--){
        cin >> x;
        nums1.push_back(x);
    }

    vector<int> nums2;
    while(m--) {
        cin >> x;
        nums2.push_back(x);
    }

    vector<int> nums3;
    while(k--) {
        cin >> x;
        nums3.push_back(x);
    }
    cout << solve(nums1, nums2, nums3);
}