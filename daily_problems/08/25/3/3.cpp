#include <bits/stdc++.h>

using namespace std;

void solve(int n, int x, int y, int z) {
    int ans = 0, d1 = 0, d2 = 0;
    for(int i = 1; i <= 99999; i++) {
        int total = n * i;
        if (total > 99999) break;
        if ((total / 1000) % 10 == x && (total / 100) % 10 == y && (total / 10) % 10 == z) {
            ans = i;
            d1 = (total / 10000) % 10;
            d2 = total % 10;
        }
    }
    if (ans == 0) cout << 0 << '\n';
    else cout << d1 << ' ' << d2 << ' ' << ans << '\n';
}


// 上海交通大学 Old Bill
int main() {
    int N, X, Y, Z; while(cin >> N >> X >> Y >> Z)
    solve(N, X, Y, Z);
}