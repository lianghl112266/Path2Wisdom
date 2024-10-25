#include <bits/stdc++.h>

using namespace std;

void solve(string s) {
    unordered_map<char, int> mp;
    for(int i = 0; i < 10; i++) mp['0' + i] = i;
    mp['a'] = 10; mp['b'] = 11;

    int d = 0;
    for(int i = 0; i < s.size(); i++) cout << mp[s[i]] << " ";
    cout << '\n';

    for(int i = s.size()-1, base = 1; i >= 0; i--) {
        d += base * mp[s[i]];
        base *= 12;
    }

    cout << d << '\n';

    string ss = "";
    for(int i = 31; i >= 0; i--) ss += ((d >> i) & 1) == 1 ? '1' : '0';
    for(int i = 0; i < 32; i += 8) cout << ss.substr(i, 8) << " ";
}


int main() {
    string s; cin >> s;
    solve(s);
}