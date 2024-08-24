#include <bits/stdc++.h>

using namespace std;

//火车票订购
int main() {
    int m, n; cin >> n >> m;
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++) {
        bool flag = true;
        int a, b, k; cin >> a >> b >> k;
        for(int i = a; i <= b; i++) {
            mp[i] += k;
            if (mp[i] > m) flag = false;
        }
        if (!flag) for(int i = a; i <= b; i++) mp[i] -= k;
        cout << flag << '\n';
    }
}