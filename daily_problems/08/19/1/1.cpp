#include <bits/stdc++.h>

using namespace std;

struct Stu {
    string id;
    int x, y, z;
};

int main() {
    int n; cin >> n;
    vector<Stu> stus(n);
    for(int i = 0; i < n; i++) {
        cin >> stus[i].id >> stus[i].x >> stus[i].y >> stus[i].z;
    }
    sort(stus.begin(), stus.end(), [](const Stu s1, const Stu s2) -> bool {return s1.x + s1.y + s2.z > s2.x + s2.y + s2.z;});
    for(auto s: stus) cout << s.id << " " << s.x << " " << s.y << " " << s.z << '\n';
}
