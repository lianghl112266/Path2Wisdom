#include <bits/stdc++.h>

using namespace std;

void solve(string s, string t) {
	int n = s.size(), m = t.size();
	vector<vector<int>> memo(n, vector<int>(m, -1));
	function<int(int, int)> f = [&](int i, int j) -> int {
		if (i < 0 || j < 0) return 0;
		if (memo[i][j] != -1) return memo[i][j];
		return memo[i][j] = max(max(f(i-1, j), f(i, j-1)), s[i] == t[j] ? f(i-1, j-1) + 1 : 0);
	};
	cout << f(n-1, m-1);
}

// 上海交通大学 Coincidence
int main() {
 string s, t; cin >> s >> t;
	solve(s, t);
}