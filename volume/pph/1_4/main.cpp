#include <bits/stdc++.h>

using namespace std;



void solve(vector<int> &a) {
    int n = a.size();

    if (n == 1 || a[0] > a[1]) {
        cout << a[0] << '\n';
        return;
    }

    int i = 1, j = n - 1;
    while (i <= j) {
        int mid = (i + j) / 2;
        if (a[mid] > a[mid-1]) i = mid + 1;
        else j = mid - 1;
    }

    cout << a[i-1] << '\n';
}


int main() {
    freopen("input.txt", "r", stdin);
    int t; cin >> t; while(t--)
    {
        int n; cin >> n;
        vector<int> a(n); for(int i = 0; i < n; i++) cin >> a[i];
        solve(a);
    }
}