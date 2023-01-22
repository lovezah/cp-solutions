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
int n, q, a[N];
int siz[N], par[N], dep[N];
VI adj[N], seq;
int st[N], en[N], top[N];
void dfs1(int u) {
    siz[u] = 1;
    trav(v, adj[u]) {
        dep[v] = dep[u] + 1;
        par[v] = u;
        adj[v].erase(find(ALL(adj[v]), u));
        dfs1(v);
        siz[u] += siz[v];
        if (siz[v] > siz[adj[u][0]]) swap(adj[u][0], v);
    }
}
void dfs2(int u) {
    st[u] = SZ(seq);
    seq.pb(u);
    trav(v, adj[u]) {
        top[v] = (v == adj[u][0] ? top[u] : v);
        dfs2(v);
    }
    en[u] = SZ(seq);
}

const int MX = 1<<18;
ll seg[MX*2];
ll cmb(ll a, ll b) { return a+b; }
void pull(int p) {
    seg[p] = cmb(seg[p*2], seg[p*2+1]);
}
void upd(int x, int v) {
    seg[x+MX] = v;
    for (int i = (x+MX)/2; i; i/=2) pull(i);
}
ll qry(int l, int r) {
    ll res = 0;
    for (int lo = l+MX, hi = r+MX; lo < hi; lo/=2, hi/=2) {
        if (lo&1) res += seg[lo++];
        if (hi&1) res += seg[--hi];
    }
    return res;
}
ll qry2(int l, int r) {
    ll res = 0;
    while (top[l]^top[r]) {
        if (dep[top[l]] < dep[top[r]]) swap(l, r);
        res += qry(st[top[l]], st[l]+1);
        l = par[top[l]];
    }
    //dbg("down", l, r);
    if (dep[l] > dep[r]) swap(l, r);
    res += qry(st[l], st[r]+1);
    return res;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> q;
    F0R(i, n) cin >> a[i];
    rep(n-1) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs1(0);
    top[0] = 0;
    dfs2(0);
    F0R(i, n) seg[st[i]+MX] = a[i];
    FORd(i, 1, MX) pull(i);
    rep(q) {
        int t, s; cin >> t >> s;
        s--;
        if (t == 1) {
            int x; cin >> x;
            upd(st[s], x);
        } else {
            cout << qry2(0, s) << '\n';
        }
    }
    return 0;
}

