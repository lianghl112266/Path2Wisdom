#include <bits/stdc++.h>

using namespace std;


/**
 * 来自王道教材2.2线性表的顺序表示找小结第5题  
 * 
 * 思路：  
 * 你都假设数据在n这个范围内， 我用set不过分吧
 * 
 * 时间复杂度O(n), 空间复杂度O(1)  
 */

void solve(vector<int> a) {
    unordered_set<int> st;
    vector<int> b;
    for(auto c: a) {
        if (st.find(c) == st.end()) {
            st.insert(c);
            b.emplace_back(c);
        }
    }
    for(auto c: b) cout << c << " ";
}


int main() {
    solve({3, 6, 9, 3});
}