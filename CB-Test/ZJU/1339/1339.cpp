// https://noobdream.com/DreamJudge/Issue/page/1339/

#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, a, b) for (int i = (int)(a); i >= (int)b; --i)
#define fori(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define loop while(1)
#define ms(x, y) memset(x, y, sizeof(x))
#define sz(x) int(x.size())
#define fk cerr<<"fk"<<endl
#define db(x) cerr<<(#x)<<'='<<(x)<<endl
#define db2(x,y) cerr<<(#x)<<'='<<(x)<<' '<<(#y)<<'='<<(y)<<endl
#define lowbit(a) ((a)&-(a))
#define random(a,b) ((a)+rand()%((b)-(a)+1))
using namespace std;
using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
const double PI = acos(-1);
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 2e6+10;

#define LOCAL_DEFINE
//#define MORE_CASE

void solve() {
    unordered_map<string, string> dic;
    loop {
        string s; getline(cin, s);
        if (s == "@END@") break;
        int pos = s.find(']');
        string slogan = s.substr(1, pos-1);
        string func = s.substr(pos+2, s.length());
        dic[slogan] = func;
    }

    int n; cin >> n; cin.get();
    forn(i, n) {
        string s; getline(cin, s);
        if (s[0] == '[') s = s.substr(1, s.length() - 2);
        bool find = false;
        for(auto &[k, v]: dic) if (k == s || v == s) {
            cout << (k == s ? k : v) << '\n';
            find = true;
            break;
        }
        if (!find) cout << "what?\n";
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifdef LOCAL_DEFINE
    freopen("input.txt", "r", stdin);
#endif

#ifdef MORE_CASE
    int T;
    cin >> T; while(T--)
#endif
    solve();
    return 0;
}