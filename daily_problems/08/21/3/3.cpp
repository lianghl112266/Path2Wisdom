#include <bits/stdc++.h>

using namespace std;


void solve(int s, int t) {
    int ans = 0;
    bool find = false;
    vector<int> q {t};
    unordered_map<int, int> route;
    for(ans = 0; !q.empty(); ans++) {
        vector<int> p(q);
        q.clear();
        for(auto x: p) {
            if (x == s) {
                find = true;
                break;
            }
            if (route.find(x+1) == route.end()) {
                route[x+1] = x;
                q.push_back(x+1);
            }
            if (route.find(x-1) == route.end()) {
                route[x-1] = x;
                q.push_back(x-1);
            }
            if (x%2 == 0 && route.find(x/2) == route.end()) {
                route[x/2] = x;
                q.push_back(x/2);
            }
        }
        if (find) break;
    }
    cout << ans << endl;
    int x = s;
    while(x != t) {
        cout << x << "->";
        x = route[x];
    }
    cout << t;
}


int main() {
    int s, t; cin >> s >> t;
    solve(s, t);
}