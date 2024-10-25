#include <bits/stdc++.h>

using namespace std;


void solve(vector<int> a, int x) {
    int ans = -1, n = a.size();
    for(int i = 0; i < n; i++) if (a[i] == x) {
        ans = i;
        break;
    }
    cout << ans;
}

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int x; cin >> x;
    solve(a, x);
}