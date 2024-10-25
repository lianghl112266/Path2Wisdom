// https://noobdream.com/DreamJudge/Issue/page/1315/

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
    int n, m; cin >> n >> m;
    unordered_map<char, char> son;
    forn(i, n) {
        string s; cin >> s;
        if (s[1] != '-') son[s[1]] = s[0];
        if (s[2] != '-') son[s[2]] = s[0];
    }
    auto f = [&](char fa, char ch) -> int { //得到亲属距离
        int cnt = 0;
        while(ch != fa && son.find(fa) != son.end()) {
            fa = son[fa];
            cnt += 1;
        }
        return ch == fa ? cnt : -1;
    };

    auto fixS = [&](int cnt, string base) -> string { //根据parent或child得到答案
        string ans = base;
        if (cnt >= 2) {
            ans = "grand" + base;
            for(cnt -= 2; cnt; cnt--) ans = "great-" + ans;
        }
        return ans;
    };
    forn(i, m) {
        string s; cin >> s;
        // cnt1为 s[0] 为 s[1] 的父
        // cnt2为 s[1] 为 s[2] 的父
        int cnt1 = f(s[0], s[1]), cnt2 = f(s[1], s[0]);
        if (cnt1 != -1) cout << fixS(cnt1, "parent") << '\n';
        else if (cnt2 != -1) cout << fixS(cnt2, "child") << '\n';
        else cout << "-\n";
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