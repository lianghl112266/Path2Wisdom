#include <bits/stdc++.h>

using namespace std;


// 3.1栈  3
void solve(string s) {
    int cnt = 0;
    for(auto c: s) {
        if (c == 'O' && --cnt < 0) {
            cout << "false" << '\n';
            return;
        }
        cnt++;
    }
    cout << "true" << '\n';
}


int main() {
    string s; cin >> s;
    solve(s);
}