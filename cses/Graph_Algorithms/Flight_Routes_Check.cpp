#include <bits/stdc++.h>
using namespace std;
namespace zah339 {
#ifdef LOCAL
#include "E:\cp-Library\debug.h"
#else
#define dbg(...)
#endif

#define ALL(x) (x).begin(), (x).end() 
#define RALL(x) (x).rbegin(), (x).rend()
#define SZ(x) (int((x).size()))
#define REV(x) reverse(ALL(x))
#define	UNIQUE(x) sort(ALL(x)), x.erase(unique(ALL(x)), x.end())
#define mask(x) (1 << (x))
#define fi first
#define se second
#define pb push_back
#define eb emplace_back 
#define mp make_pair
#define ins insert
#define lb lower_bound
#define ub upper_bound

template<class T>
using V = std::vector<T>;
template<class T, size_t sz>
using AR = std::array<T, sz>;
using ll = int64_t;
using db = double;
using str = std::string;
using pi = std::pair<int, int>;
using pl = std::pair<ll, ll>;
using VI = V<int>;
using VL = V<ll>;
using VS = V<str>;
using VB = V<bool>;
using VPI = V<pi>;

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

template<class T> using pq = std::priority_queue<T>;
template<class T> using pqg = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template<class T> bool ckmax(T &u, T v) { return v > u ? u = v, true : false; }
template<class T> bool ckmin(T &u, T v) { return v < u ? u = v, true : false; }

#define FOR(i, a, n) for (int i = (a); i < (n); i++)
#define F0R(i, n) FOR(i, 0, n)
#define FORd(i, a, n) for (int i = (n) - 1; i >= (a); i--)
#define F0Rd(i, n) FORd(i, 0, n)
#define rep(n) F0R(_, n)
#define trav(a, v) for (auto &a : v)
#define each(a, b, v) for (auto &&[a, b] : v)
#define each3(a, b, c, v) for (auto &&[a, b, c] : v)
} // namespace zah339
using namespace zah339;

const int N = 100010;
int n, m, cnt;
VI adj[N];
int bel[N], low[N], dfn[N], ck = 0, in[N];
VI stk;
V<VI> scc;
void dfs(int u) {
    low[u] = dfn[u] = ++ck;
    in[u] = 1;
    stk.pb(u);
    trav(v, adj[u]) {
        if (!dfn[v]) {
            dfs(v);
            ckmin(low[u], low[v]);
        } else if (in[v]) ckmin(low[u], dfn[v]);
    }
    if (low[u] == dfn[u]) {
        VI res;
        ++cnt;
        while (true) {
            int x = stk.back(); stk.pop_back();
            in[x] = 0;
            bel[x] = cnt;
            res.pb(x);
            if (x == u) break;
        }
        scc.pb(res);
    }
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> m;
    rep(m) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
    }
    F0R(i, n) bel[i] = -1;
    F0R(i, n) if (bel[i] < 0) {
        dfs(i);
    }
    F0R(i, n) {
        cout << bel[i] << " \n"[i+1==n];
    }
    if (SZ(scc) == 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
        FOR(i, 1, n) {
            if (bel[i] != bel[0]) {
                cout << i+1 << ' ' << 1 << '\n';
                exit(0);
            }
        }
    }
    return 0;
}

