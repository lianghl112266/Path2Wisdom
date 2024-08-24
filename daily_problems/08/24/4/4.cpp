#include <bits/stdc++.h>

using namespace std;

//中国科学技术大学 小偷的背包
void solve(int s, int n, vector<int> a) {
    function<bool(int, int)> f = [&](int i, int r) -> bool {
        if (i == n || r <= 0) return r == 0;
        return f(i+1, r) || f(i+1, r - a[i]);
    };
    cout << (f(0, s) ? "yes!" : "no!") << '\n';
}

int main() {
    int s, n; cin >> s >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    solve(s, n, a);
}