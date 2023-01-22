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

const int MX = 1<<18, N = 200010;
int n, q;
ll seg[MX*2], lazy[MX*2];
ll cmb(ll a, ll b) { return a+b; }
void pull(int p) { seg[p] = cmb(seg[p*2], seg[p*2+1]); }
void push(int p, int l, int r) {
    ll cnt = r-l;
    int m = (l+r)/2;
    if (!lazy[p]) return;
    seg[p] += cnt*(lazy[p]+lazy[p]+cnt-1)/2;
    if (r != l+1) {
        push(p*2, l, m); push(p*2+1, m, r);
        lazy[p*2] += lazy[p];
        lazy[p*2+1] += lazy[p]+(m-l);
    }
    lazy[p] = 0;
}
void upd(int p, int l, int r, int ql, int qr) {
    push(p, l, r);
    if (r <= ql || qr <= l) return;
    if (ql <= l && r <= qr) {
        lazy[p] = l-ql+1;
        push(p, l, r);
        return;
    }
    int m = (l+r)/2;
    upd(p*2, l, m, ql, qr), upd(p*2+1, m, r, ql, qr);
    pull(p);
}
ll qry(int p, int l, int r, int ql, int qr) {
    push(p, l, r);
    if (r <= ql || qr <= l) return 0;
    if (ql <= l && r <= qr) return seg[p];
    int m = (l+r)/2;
    return cmb(qry(p*2, l, m, ql, qr), qry(p*2+1, m, r, ql, qr));
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
        int a, b; cin >> a >> b; a--;
        if (t == 1) upd(1, 0, MX, a, b);
        else cout << qry(1, 0, MX, a, b) << '\n';
    }
    
    return 0;
}

