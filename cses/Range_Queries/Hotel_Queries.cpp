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

const int MX = 1<<18;
int seg[MX*2];
int n, m;
int cmb(int a, int b) { return max(a, b); }
void pull(int p) { seg[p] = cmb(seg[p*2], seg[p*2+1]); }
int query(int lo, int hi) {
    int res = 0;
    for (int l = lo+MX, r = hi+MX; l < r; l/=2, r/=2) {
        if (l&1) ckmax(res, seg[l++]);
        if (r&1) ckmax(res, seg[--r]);
    }
    return res;
}
void upd(int p, int v) {
    seg[p+MX] -= v;
    for (int i = (p+MX)/2; i; i/=2) pull(i);
}
int qry(int p, int l, int r, int ql, int qr, int v) {
    if (qr <= l || r <= ql || seg[p] < v) return -1;
    if (r-l == 1) return l;
    int m = (l+r)/2;
    int res = qry(p*2, l, m, ql, qr, v);
    return (res != -1 ? res : qry(p*2+1, m, r, ql, qr, v));
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> m;
    F0R(i, n) {
        int x; cin >> x;
        seg[i+MX] = x;
    }
    FORd(i, 1, MX) pull(i);
    F0R(i, m) {
        int r; cin >> r;
        int pos = qry(1, 0, MX, 0, n, r);
        cout << pos+1 << ' ';
        if (~pos) upd(pos, r);
    }
    return 0;
}

