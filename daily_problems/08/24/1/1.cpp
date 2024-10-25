#include <bits/stdc++.h>

using namespace std;

// 华科 a+b
void solve(string s, string t) {
    int c = 0;
    string ans = "";
    for(int i = s.size()-1, j = t.size()-1; i >= 0 || j >= 0 || c > 0; i = i-1, j = j-1) {
        int x = i >= 0 ? s[i] - '0' : 0;
        int y = j >= 0 ? t[j] - '0' : 0;
        int sum = x + y + c;
        ans = (char(sum%10 + '0')) + ans;
        c = sum / 10;
    }
    cout << ans << '\n';
}


int main() {
    string s, t;
    while(cin >> s >> t) solve(s, t);
}