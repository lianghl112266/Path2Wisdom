#include <bits/stdc++.h>

using namespace std;

int op(stack<int>& ns, stack<char>& cs) {
    int y = ns.top();
    ns.pop();
    int x = ns.top();
    ns.pop();
    int c = cs.top();
    cs.pop();
    if (c == '+') return x + y;
    if (c == '-') return x - y;
    if (c == '*') return x * y;
    return x / y;
}

void solve(string s) {
    int i = 0, n = s.size();
    stack<int> ns;
    stack<char> cs;
    while (i < n) {
        int x = 0;
        while(isdigit(s[i])) x = x * 10 + s[i++] - '0';
        ns.push(x);
        while(!cs.empty() && (s[i] == '-' || s[i] == '+' || cs.top() == '*' || cs.top() == '/')) ns.push(op(ns, cs));
        if (i < n) cs.push(s[i++]);
    }
    cout << op(ns, cs);
}

// 上海交通大学/兰州大学2018年机试题  计算表达式
int main() {
    string s; while(cin >> s) 
    solve(s);
}