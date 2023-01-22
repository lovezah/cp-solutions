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

const int N = 200010;
int dep[N], f[20][N];
int n, q;
VI adj[N];

void dfs(int u, int par = -1) {
    trav(v, adj[u]) if (v != par) {
        f[0][v] = u;
        dep[v] = dep[u] + 1;
        dfs(v, u);
    }
}
int get_anc(int a, int b) {
    if (dep[a] < dep[b]) swap(a, b);
    F0Rd(i, 19) if (dep[f[i][a]] >= dep[b]) a = f[i][a];
    if (a == b) return a;
    F0Rd(i, 19) if (f[i][a] != f[i][b]) {
        a = f[i][a];
        b = f[i][b];
    }
    return f[0][a];
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> q;
    F0R(i, 19) F0R(j, n) f[i][j] = -1;
    rep(n-1) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(0);
    FOR(i, 1, 19) F0R(j, n) if (~f[i-1][j]) {
        f[i][j] = f[i-1][f[i-1][j]];
    }
    rep(q) {
        int a, b; cin >> a >> b;
        a--, b--;
        int anc = get_anc(a, b);
        cout << dep[a]+dep[b]-2*dep[anc] << '\n';
    }
    return 0;
}

