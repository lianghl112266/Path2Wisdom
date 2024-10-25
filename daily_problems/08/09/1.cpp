#include <bits/stdc++.h>

using namespace std;

/**
 * 来自王道教材3.4栈与队列的应用小结第1题  
 * 
 * 思路， 模拟题
 * 
 * 时间复杂度O(n), 空间复杂度O(1)  
 */


bool solve(string s) {
    auto is_pair = [&](char c) -> char {
        if (c == '}') return '{';
        if (c == ')') return '(';
        return '[';
    };

    stack<char> st;
    for (auto c: s) {
        if (c == '(' || c == '[' || c == '{') st.push(c);
        else {
            if ((st.top() != is_pair(c)) ) {
                cout << is_pair(c) << " " << st.top();
                return false;
            }
            st.pop();
        }
    }
    return true;
}


int main() {
    cout << solve("[[[[[((({{{}}})))]]]]]");
}