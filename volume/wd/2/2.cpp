#include <bits/stdc++.h>

using namespace std;

int main() {
    //读数据
    freopen("input.txt", "r", stdin);
    int n; cin >> n;
    vector<int> nums(n); for(int i = 0; i < n; i++) cin >> nums[i];

    //solve
    int odd_pos = 1;
    for(int i = 0; i < n; i += 2) {
        while(nums[i] % 2 == 1) {
            swap(nums[odd_pos], nums[i]);
            odd_pos += 2;
        }
    }

    for(int i = 0; i < n; i++) cout << nums[i] << ' ';
}