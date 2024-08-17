#include <bits/stdc++.h>

using namespace std;

using ll = long long;


struct Pair {
    int s, e;
    bool operator < (const Pair& p) const {
        return s > p.s;
    }
};


void solve(int n, vector<int>& speed, vector<int>& efficiency, int k) {
    vector<Pair> ps;
    for(int i = 0; i < n; i++) ps.push_back({speed[i], efficiency[i]});
    sort(ps.begin(), ps.end(), [](const Pair& p1, const Pair& p2) -> bool {return p1.e > p2.e;});
    ll sum = 0, ans = 0;
    priority_queue<Pair> q;
    for(auto p: ps) {
        ans = max(ans, p.e * (sum + p.s));
        q.push(p);
        sum += p.s;
        if (q.size() == k) {
            sum -= q.top().s;
            q.pop();
        }
    }
    cout << ans << endl;
}

int main() {
    int n, x, k;
    cin >> n;
    vector<int> speed(n), efficiency(n);
    for(int i = 0; i < n; i++) {
        cin >> x;
        speed[i] = x;
    }
    for(int i = 0; i < n; i++) {
        cin >> x;
        efficiency[i] = x;
    }
    cin >> k;

    solve(n, speed, efficiency, k);
}