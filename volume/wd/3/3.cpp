#include <bits/stdc++.h>

using namespace std;


int main() {
    //读数据
    freopen("input.txt", "r", stdin);
    int n; cin >> n;
    vector<int> nums(n); for(int i = 0; i < n; i++) cin >> nums[i];

    //solve
    int i = 0, j = n-1;
    while (i <= j) {
        int mid = (i + j) / 2;
        if (nums[mid] > nums[0]) i = mid + 1;
        else j = mid - 1;
    }

    cout << nums[i] << '\n';
}