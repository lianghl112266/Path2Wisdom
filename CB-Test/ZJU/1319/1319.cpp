// https://noobdream.com/DreamJudge/Issue/page/1319/

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
    loop {
        int n, m; cin >> n;
        if (n == 0) return ;
        cin >> m;
        vector<int> pa(n); iota(all(pa), 0);
        function<int(int)> find = [&](int x) -> int {
            return pa[x] == x ? pa[x] : pa[x] = find(pa[x]);
        };
        auto merge = [&](int x, int y) -> bool {
            int rx = find(x), ry = find(y);
            pa[rx] = ry;
            return rx != ry;
        };

        int target = n - 1;
        forn(i, m) {
            int x, y; cin >> x >> y;
            x--; y--;
            if (merge(x, y)) target--;
        }
        cout << target << '\n';
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