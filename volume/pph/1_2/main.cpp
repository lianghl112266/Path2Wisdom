#include <bits/stdc++.h>

using namespace std;



void solve(vector<int> &a, int k) {
    int n = a.size();
    priority_queue<int, vector<int>, greater<int>> hp;
    for(int i = 0; i < min(n, k); i++) hp.push(a[i]);
    for(int i = 0; i < n; i++) {
        if (i + k < n) hp.push(a[i+k]);
        a[i] = hp.top();
        hp.pop();
    }
    for(int i = 0; i < n; i++) cout << a[i] << ' ';
}


int main() {
    freopen("input.txt", "r", stdin);

    int n, k; cin >> n >> k;
    vector<int> a(n); for(int i = 0; i < n; i++) cin >> a[i];
    solve(a, k);
}