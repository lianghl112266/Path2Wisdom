#include <bits/stdc++.h>
#include <link.h>

using namespace std;



void solve(Node *head, int k) {
    priority_queue<int, vector<int>, less<int>> hp;
    for (Node *p = head->next; p; p = p->next) {
        hp.push(p->val);
        if (hp.size() > k) {
            hp.pop();
        }
    }
    cout << hp.top() << '\n';
}


int main() {
    freopen("input.txt", "r", stdin);
    int n, k; cin >> n >> k;
    vector<int> a(n); for(int i = 0; i < n; i++) cin >> a[i];
    Node *head = buildByTailInsert(a);
    solve(head, k);
}