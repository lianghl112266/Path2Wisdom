#include <bits/stdc++.h>

using namespace std;

vector<int> f{0, 2, 1, 4, 3};

int main() {
    string s;
    stack<pair<int, int>> st;
    while (cin >> s) {
        int i = s[0] - '0', j = stoi(s.substr(2));
        if (!st.empty()) {
            auto it = st.top();
            auto x = it.first, y = it.second;
            if (i == x || i == f[x]) {
                st.pop();
                j += (i == x ? y : -y);
                if (j < 0) {
                    i = f[i];
                    j = -j;
                }
            }
        }
        if (j != 0) st.push({i, j});
    }

    while (!st.empty()) {
        auto it = st.top();
        st.pop();
        cout << f[it.first] << '-' << it.second << ' ';
    }
    cout << '\n';
}