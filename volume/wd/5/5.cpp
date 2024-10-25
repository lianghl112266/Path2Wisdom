#include <bits/stdc++.h>

using namespace std;


int main() {
    //读数据
    freopen("input.txt", "r", stdin);
    int n; cin >> n;
    vector<int> nums(n); for(int i = 0; i < n; i++) cin >> nums[i];

    //solve
    int k = 0;
    vector<int> tmp(n);
    for(int i = 0; i < n; i += 2) tmp[k++] = nums[i];
    for(int i = 1; i < n; i += 2) tmp[k++] = nums[i];
    nums.assign(tmp.begin(), tmp.end());

    for(int i = 0; i < n; i += 1) cout << nums[i] << ' ';
}