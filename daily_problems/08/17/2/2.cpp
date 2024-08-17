#include <bits/stdc++.h>

using namespace std;


void solve(string s1, string s2) {
    const int inf = 0x3f3f3f3f;
    int n = s1.length(), m = s2.length();
    vector<vector<int>> memo(n+1, vector<int> (m+1, -1));
    function<int(int, int)> f = [&](int i, int j)->int {
        if (i < 0 || j < 0) return i == -1 && j == -1 ? 0 : inf;
        int& res = memo[i][j];
        if (res != -1) return res;
        if (s1[i] == s2[j]) return res = f(i-1, j-1);
        return res = min(f(i-1, j), min(f(i-1, j-1), f(i, j-1))) + 1;
    };

    cout << f(s1.length()-1, s2.length()-1) << endl;
}


int main() {
    string s1, s2;
    cin >> s1 >> s2;
    solve(s1, s2);
}