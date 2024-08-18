#include <bits/stdc++.h>

using namespace std;


void solve(int n, vector<int> last) {
    vector<int> f(n);
    for(int i = 1; i < n; i++) {
        f[i] = f[i-1] + 1;
        if (last[i] != -1) f[i] = min(f[i], f[last[i]] + 1);
    }
    cout << f[n-1];
}


int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    
    int n, x; cin >> n;
    unordered_map<int, int> m;
    vector<int> last(n);
    for(int i = 0; i < n; i++) {
        cin >> x;
        if (m.find(x) == m.end()) last[i] = -1;
        else last[i] = m[x];
        m[x] = i;
    }
    solve(n, last);
}