#include <bits/stdc++.h>

using namespace std;

// 中国科学技术大学 任务调度
void solve(int n, vector<string> tasks) {
    vector<vector<int>> g(n);
    regex pattern("Task(\\d+)");
    vector<int> deg(n);
    for(auto t: tasks) {
        sregex_iterator next(t.begin(), t.end(), pattern);
        sregex_iterator end;
        vector<int> numbers;
        for (sregex_iterator i = next; i != end; ++i) {
            smatch match = *i;
            string num_str = match[1].str();
            numbers.push_back(stoi(num_str));
        }
        int x = numbers[0];
        for(int i = 1; i < numbers.size(); i++) {
            int y = numbers[i];
            g[x].push_back(y);
            deg[y]++;
        }
    }
    vector<int> q;
    for(int i = 0; i < n; i++) if (deg[i] == 0) q.push_back(i);
    while(!q.empty()) {
        vector<int> p(q);
        q.clear();
        for(auto x: p) {
            cout << "Task" << x << ' ';
            for(auto y: g[x]) {
                if (--deg[y] == 0) q.push_back(y);
            }
        }
        sort(q.begin(), q.end());
    }
}

int main() {
    int n; cin >> n;
    vector<string> tasks(n);
    for(int i = 0; i < n; i++) cin >> tasks[i];
    solve(n, tasks);
}