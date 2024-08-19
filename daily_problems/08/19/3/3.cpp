#include <bits/stdc++.h>

using namespace std;

int dis(pair<int, int> p1, pair<int, int> p2) {
    return (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
}

int main() {
    vector<pair<int, int>> points(8);
    for(int i = 0; i < 8; i++) cin >> points[i].first >> points[i].second;
    pair<int, int> ans;
    int mi = 0x3f3f3f3f;
    for(int i = 0; i < 8; i++) for(int j = i+1; j < 8; j++) {
        int d = dis(points[i], points[j]);
        if(d < mi) {
            ans = {i, j};
            mi = d;
        }
    }
    cout << points[ans.first].first << " " << points[ans.first].second << '\n';
    cout << points[ans.second].first << " " << points[ans.second].second << '\n';
}
