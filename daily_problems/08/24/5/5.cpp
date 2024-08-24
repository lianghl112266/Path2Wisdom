#include <bits/stdc++.h>

using namespace std;


void solve(int s) {
    string ans = "";
    for(int i = 31; i >= 0; i--) ans += (s >> i) & 1 ? '1' : '0';
    cout << ans.substr(ans.find('1')) << '\n';
}

//中国科学技术大学 栈
int main() {
    int s; cin >> s;
    solve(s);
}