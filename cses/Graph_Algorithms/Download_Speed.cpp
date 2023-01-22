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

struct edge {
    int to;
    ll cap;
    edge (int to, ll cap) : to(to), cap(cap) {}
};
V<edge> e;
VI g[510];
VI lev, ptr;
int n, m;
void ae(int a, int b, ll c) {
    g[a].pb(SZ(e));
    e.eb(b, c);
    g[b].pb(SZ(e));
    e.eb(a, 0);
}
bool bfs(int s, int t) {
    lev.assign(n+2, -1);
    lev[s] = 0;
    VI que = {s};
    F0R(z, SZ(que)) {
        int u = que[z];
        for (int i = 0; i < SZ(g[u]); i++) {
            const int j = g[u][i];
            auto [v, c] = e[j];
            if (lev[v] == -1 && c > 0) {
                lev[v] = lev[u] + 1;
                if (v == t) return true;
                que.pb(v);
            }
        }
    }
    return false;
}
ll dfs(int u, int t, ll f) {
    if (u == t) return f;
    ll r = f;
    for (int &i = ptr[u]; i < SZ(g[u]); i++) {
        const int j = g[u][i];
        auto [v, c] = e[j];
        if (lev[v] == lev[u] + 1 && c > 0) {
            auto a = dfs(v, t, min(c, r));
            e[j].cap -= a;
            e[j^1].cap += a;
            r -= a;
            if (!r) return f;
        }
    }
    return f-r;
}
ll maxFlow(int s, int t) {
    ll res = 0;
    while (bfs(s, t)) {
        ptr.assign(n+2, 0);
        res += dfs(s, t, 4e18);
    }
    return res;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> m;
    rep(m) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        ae(a, b, c);
    }
    int s = n, t = n+1;
    ae(s, 0, 4e18);
    ae(n-1, t, 4e18);
    cout << maxFlow(s, t) << '\n';
    return 0;
}

