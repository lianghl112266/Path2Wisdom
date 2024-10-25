#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, x; cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m));
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> a[i][j];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> x;
            cout << a[i][j] + x << ' ';
        }
        cout << '\n';
    }
}