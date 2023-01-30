#include <bits/stdc++.h>
namespace newbiezah {
#ifdef LOCAL
#include "E:\cp-Library\debug.h"
#else
#define dbg(...)
#endif

#define ALL(x) (x).begin(), (x).end() 
#define RALL(x) (x).rbegin(), (x).rend()
#define SZ(x) (int((x).size()))
#define REV(x) reverse(ALL(x))
#define UNIQUE(x) sort(ALL(x)), x.erase(unique(ALL(x)), x.end())
#define mask(x) (1 << (x))
#define fi first
#define se second
#define ft front()
#define bk back()
#define ppb pop_back()
#define ppf pop_front()
#define pb push_back
#define pf push_front
#define eb emplace_back 
#define mp make_pair
#define ins insert
#define lb lower_bound
#define ub upper_bound
#define tcT template<class T

tcT> using V = std::vector<T>;
tcT> int ilb(V<T> &a, const T &b) { return int(lb(ALL(a), b) - a.begin()); }
tcT> int iub(V<T> &a, const T &b) { return int(ub(ALL(a), b) - a.begin()); }
tcT, size_t sz>
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
using VPL = V<pl>;

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

tcT> using pq = std::priority_queue<T>;
tcT> using pqg = std::priority_queue<T, std::vector<T>, std::greater<T>>;
tcT> bool ckmax(T &u, T v) { return v > u ? u = v, true : false; }
tcT> bool ckmin(T &u, T v) { return v < u ? u = v, true : false; }

#define FOR(i, a, n) for (int i = (a); i < (n); i++)
#define F0R(i, n) FOR(i, 0, n)
#define FORd(i, a, n) for (int i = (n) - 1; i >= (a); i--)
#define F0Rd(i, n) FORd(i, 0, n)
#define rep(n) F0R(_, n)
#define trav(a, v) for (auto &a : v)
#define each(a, b, v) for (auto &&[a, b] : v)
#define each3(a, b, c, v) for (auto &&[a, b, c] : v)

const char nl = '\n';
const int mod1 = int(1e9)+7, mod9 = 998244353;
const int dxi[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dyi[8] = {0, 1, 0, -1, 1, -1, 1, -1};
} // namespace newbiezah
using namespace newbiezah;
using namespace std;

struct TwoSat {
    int n, ti, scc;
    std::vector<std::vector<int>> adj;
    std::vector<int> stk, val, comp, dfn;
    TwoSat(int n) : n(n), adj(2*n) {}

    int addVar() {
        adj.emplace_back();
        adj.emplace_back();
        return n++;
    }
    void addEdge(int u1, int c1, int u2, int c2) {
        adj[2*u1+!c1].push_back(2*u2+c2);
        adj[2*u2+!c2].push_back(2*u1+c1);
    }
    int dfs(int u) {
        int low = dfn[u] = ++ti;
        stk.push_back(u);
        for (auto &v : adj[u]) if (comp[v] < 0) {
            low = std::min(low, dfn[v] ?: dfs(v));
        }
        if (low == dfn[u]) {
            ++scc;
            while (1) {
                int v = stk.back(); stk.pop_back();
                comp[v] = scc;
                if (v == u) break;
            }
        }
        return low;
    }
    bool gen() {
        ti = scc = 0;
        val.assign(n, 0), stk.clear();
        comp.assign(2*n, -1), dfn.assign(2*n, 0);
        for (int i = 0; i < 2*n; i++) if (!dfn[i]) dfs(i);
        for (int i = 0; i < n; i++) {
            if (comp[2*i] == comp[2*i+1]) return false;
            val[i] = comp[2*i] < comp[2*i+1] ? 0 : 1;
        }
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    TwoSat ts(m);
    rep(n) {
        char c1, c2;
        int u1, u2;
        cin >> c1 >> u1 >> c2 >> u2;
        u1--, u2--;
        int v1 = (c1 == '+'), v2 = (c2 == '+');
        ts.addEdge(u1, v1, u2, v2);
    }
    if (!ts.gen()) {
        cout << "IMPOSSIBLE" << nl;
    } else {
        F0R(i, m) {
            char ans = '-';
            if (ts.val[i]) ans = '+';
            cout << ans << ' ';
        }
    }
    return 0;
}

