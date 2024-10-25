// https://noobdream.com/DreamJudge/Issue/page/1312/

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
const double PI = acos( -1 );  
const int INF = 0x3f3f3f3f;  
const int MOD = 1e9 + 7;  
const int N = 2e6+10;  
//-----------------------------------------------------------------------


#define LOCAL_DEFINE
//#define MORE_CASE


void solve() {
    int n, m;
    loop {
    	cin >> m >> n;
    	if (m == 0) return ;
    	vector<tuple<int, int, int>> edges;
    	forn(i, m) {
    		int x, y, w;
    		cin >> x >> y >> w;
			x--; y--;
    		edges.eb(x, y, w);
    	}
		sort(all(edges), [](const tuple<int, int, int> &a, const tuple<int, int, int> &b) {return get<2>(a) < get<2>(b);});

    	vector<int> pa(n); iota(all(pa), 0);
    	function<int(int)> find = [&](int x) -> int {
			return pa[x] == x ? x : pa[x] = find(pa[x]);
    	};
    	auto merge = [&](int x, int y) -> bool {
			int rx = find(x), ry = find(y);
    		pa[rx] = ry;
    		return rx != ry;
    	};

    	int ans = 0, cnt = 0;
    	for(auto &[x, y, w]: edges) {
    		if (merge(x, y)) {
    			ans += w;
    			if (++cnt == n-1) break;
    		}
    	}
    	if (cnt == n-1) cout << ans << '\n';
    	else cout << "?";
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


