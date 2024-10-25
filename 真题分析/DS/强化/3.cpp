/**
 * 二分查找第一个等于k的和最后一个等于k的位置即可
 * 由于bisect（k）求第一个>=k的位置， 所以bisect（k+1）求第一个大于k的位置
 * 故bisect（k+1）-1即最后一个等于k的位置
 * 
 * 时间复杂度O(log n),空间复杂度O(1)
 * 
 */



#include <bits/stdc++.h>

using namespace std;


int bisect(vector<int> nums, int k) {
    int i = 0, j = nums.size()-1;
    while(i <= j) {
        int mid = (i + j) / 2;
        if(nums[mid] < k) i = mid + 1;
        else j = mid - 1;
    }
    return i;
}


void solve(vector<int> nums, int k) {
    int i = bisect(nums, k);
    int j = bisect(nums, k+1)-1;
    cout << j - i + 1;
}


int main() {
    int n, x; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> x; a[i] = x;
    }
    solve(a, 2);
}