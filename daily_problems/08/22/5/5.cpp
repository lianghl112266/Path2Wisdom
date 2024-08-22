#include <bits/stdc++.h>

using namespace std;


void solve(string s) {
    vector<int> cnt(26);
    int mx = 0, space = 0;
    for(int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            space++;
            continue;
        }
        if ('A' <= s[i] && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
        int idx = s[i] - 'a';
        mx = max(mx, ++cnt[idx]);
    }
    
    cout << s.size() - space << '\n';
    cout << space + 1 << '\n';

    for(int i = 0; i < 26; i++) if (cnt[i] == mx) cout << char('a' + i) << ' ';
    cout << '\n';
    cout << mx;
}


int main() {
    string s; getline(cin, s);
    solve(s);
}