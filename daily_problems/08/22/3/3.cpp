#include <bits/stdc++.h>

using namespace std;

void solve(vector<int> a) {
    int n = a.size();
    for (int d = n / 2; d >= 1; d /= 2) {
        for (int i = d; i < n; i++) {
            if (a[i - d] > a[i]) {
                int x = a[i], j;
                for (j = i - d; j >= 0 && a[j] > x; j -= d) a[j + d] = a[j];
                a[j + d] = x;
            }
        }
    }
    for (auto x : a) cout << x << " ";
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    solve(a);
}