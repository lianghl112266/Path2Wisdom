#include <bits/stdc++.h>

using namespace std;


void solve(int x, int y) {
    auto rev = [&](int x) -> int {
        int res = 0;
        while(x) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    };
    if (rev(x) + rev(y) == rev(x + y)) cout << x + y << '\n';
    else cout << "NO" << '\n';
}


// 上海交通大学 数字反转
int main() {
    int x, y; while(cin >> x >> y)
    solve(x, y);
}