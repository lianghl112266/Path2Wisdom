#include <bits/stdc++.h>

using namespace std;


void solve(int n, vector<int> a) {
    int i = 1;
    for(int j = 0; j < n; j++) if (a[i-1] != a[j]) a[i++] = a[j];
    for(int k = 0; k < i; k++) cout << a[k] << ' ';
}

/**
 * 抓码
 * 2.4.1 第三题
 */
int main() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    solve(n, a);
}