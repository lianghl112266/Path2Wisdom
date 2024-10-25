// https://noobdream.com/DreamJudge/Issue/page/1344/

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
        int n, m; cin >> n >> m;
        if (n == 0 && m == 0) return;
        vector<vector<pair<int, int>>> g(n, vector<pair<int, int>> (n, mp(INF, INF)));
        forn(i, m) {
            int f, t, d, c; cin >> f >> t >> d >> c;
            f--; t--;
            g[f][t] = mp(d, c);
            g[t][f] = mp(d, c);
        }

        int start, end; cin >> start >> end;
        start--; end--;
        int dis[n]; ms(dis, 0x3f); dis[start] = 0;
        int cost[n]; ms(cost, 0x3f); cost[start] = 0;
        bool vis[n]; ms(vis, false);
        loop {
            int x = -1;
            forn(i, n) if (!vis[i] && (x == -1 || dis[i] < dis[x] || (dis[i] == dis[x] && cost[i] < cost[x]))) x = i;
            if (x == -1) break;
            vis[x] = true;
            forn(y, n) {
                int newD = g[x][y].fi + dis[x], newC = g[x][y].se + cost[x];
                if (newD < dis[y] || (newD == dis[y] && newC < cost[y])) {
                    dis[y] = newD;
                    cost[y] = newC;
                }
            }
        }
        cout << dis[end] << ' ' << cost[end] << '\n'; 
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