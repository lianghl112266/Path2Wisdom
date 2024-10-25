#include <bits/stdc++.h>

using namespace std;


int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> a[i][j];
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
        int x; cin >> x;
        a[i][j] += x;
    }
    for(auto row: a) {
        for(auto x: row) cout << x << " ";
        cout << '\n';
    }
}

