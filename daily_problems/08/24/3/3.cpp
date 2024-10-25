#include <bits/stdc++.h>

using namespace std;


int gcd(int x, int y) {
    if (y == 0) return x;
    return gcd(y, x%y);
} 

//最大公约数1
int main() {
    int n, x, mi = INT_MAX, mx = INT_MIN;
    for(cin >> n; n > 0; n--) {
        cin >> x;
        mi = min(mi, x);
        mx = max(mx, x);
    }
    cout << mi << ' ' << mx << ' ' << gcd(mi, mx) << '\n';
}