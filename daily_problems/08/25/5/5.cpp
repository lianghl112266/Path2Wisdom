#include <bits/stdc++.h>

using namespace std;


void solve(int n) {
    int ans = 0;
    while(n >= 5) {
        int k = n / 5;
        ans += k;
        n /= 5;
    }
    cout << ans << '\n';
}

// 上海交通大学 求n的阶乘末尾连续0的个数
int main() {
    int n; while(cin >> n)
    solve(n);
}