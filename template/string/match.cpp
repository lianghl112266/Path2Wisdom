#include <bits/stdc++.h>

using namespace std;

#define kmp


class StringMatch {
    private:
    vector<int> getNext(string s) {
        int n = s.size();
        vector<int> next(n);
        next[0] = -1;
        for(int i = 2; i < n; i++) {
            for(int j = i - 1; j >= 1; j--) {
                string a = s.substr(0, j);
                string b = s.substr(i-j, j);
                if (a == b) next[i] = j;
            }
        }
        return next;
    }

    public:
    int matchSimple(string s, string t) {
        int i = 0, j = 0, n = s.size(), m = t.size();
        while(i < n && j < m) {
            if (s[i] == t[j]) {
                i++;j++;
            }else {
                i = i - j + 1; j = 0;
            }
        }
        if (j >= m) return i - m;
        return -1;
    }

    int matchKMP(string s, string t) {
        int i = 0, j = 0, n = s.size(), m = t.size();
        vector<int> next = getNext(t);
        while(i <= n && j <= m) {
            if (j == -1 || s[i] == t[j]) {
                i++;j++;
            }
            else {
                j = next[j];
            }
        }
        if (j >= m) return i - m;
        return-1;
    }
};





int main() {
    string s, t; cin >> s >> t;
    auto match = StringMatch();
#ifdef kmp
    match.matchKMP(s, t);
#else
    match.matchSimple(s, t);
#endif
}
