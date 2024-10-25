/**
 * 
 * 来自王道绿书算法章节数组第一题P104
 * 
 * 前后都是有序， 然后查找某个元素， 直接二分即可
 * 时间复杂度O(log n), 空间复杂度O(1)
 * 
 * 
 */


#include <bits/stdc++.h>

using namespace std;


int bisect(vector<int>& a, int i, int j, int k, bool up) {
    while(i <= j) {
        int mid = (i+j)/2;
        if(a[mid]==k) return mid;
        if (up) {
            if (a[mid] < k) i = mid+1;
            else j = mid-1;
        } else {
            if (a[mid] < k) j = mid-1;
            else i = mid+1;
        }
    }
    return -1;
}

int solve(vector<int>& a, int k) {
    int n = a.size();
    return max(bisect(a, 0, n/2, k, false), bisect(a, n/2, n-1, k, true));
}


int main() {
    vector<int> a{10, 7, 5, 2, 6, 13, 15};
    cout << solve(a, 5) << endl;
    cout << solve(a, 8) << endl;
}