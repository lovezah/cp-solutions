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
 
const int N = 200010, MX = 1<<18;
int n, q;
int a[N];
ll seg[MX*2], lazy[MX*2];
ll cmb(ll a, ll b) { return a + b; }
void push(int u, int l, int r) {
    seg[u] += lazy[u] * (r-l);
    if (l != r-1) F0R(i, 2) lazy[u*2+i] += lazy[u];
    lazy[u] = 0;
}
void pull(int u) { 
    seg[u] = cmb(seg[u*2], seg[u*2+1]);
}
void upd(int u, int l, int r, int ql, int qr, int v) {
    push(u, l, r);
    if (r <= ql || qr <= l) return;
    if (ql <= l && r <= qr) {
        lazy[u] = v;
        push(u, l, r); return;
    }
    int m = (l+r)/2;
    upd(u*2, l, m, ql, qr, v); upd(u*2+1, m, r, ql, qr, v);
    pull(u);
}
ll qry(int u, int l, int r, int ql, int qr) {
    push(u, l, r);
    if (r <= ql || qr <= l) return 0;
    if (ql <= l && r <= qr) return seg[u];
    int m = (l+r)/2;
    return cmb(qry(u*2, l, m, ql, qr), qry(u*2+1, m, r, ql, qr));
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
 
    cin >> n >> q;
    F0R(i, n) {
        int x; cin >> x;
        seg[i+MX] = x;
    }
    FORd(i, 1, MX) pull(i);
    rep(q) {
        int t; cin >> t;
        if (t == 1) {
            int a, b, u; cin >> a >> b >> u;
            a--;
            upd(1, 0, MX, a, b, u);
        } else {
            int k; cin >> k;
            k--;
            cout << qry(1, 0, MX, k, k+1) << '\n';
        }
    }
    return 0;
}
