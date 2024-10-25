#include <bits/stdc++.h>

using namespace std;


void solve(string s) {
    int x = 0;
    for(auto c: s) if (isdigit(c)) x = x * 10 + c - '0';
    for(int i = 2; i < x; i++) {
        if (x % i == 0) {
            cout << (x/i) << '\n';
            return;
        }
    }
    cout << 0 << '\n';
}


int main() {
    int T; cin >> T;
    while(T--) {
        string s;
        cin >> s;
        solve(s);
    }
}