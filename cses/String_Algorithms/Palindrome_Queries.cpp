#include <bits/stdc++.h>
using namespace std;
namespace zah233 {
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

const char nl = '\n';
const int mod1 = int(1e9)+7;
const int mod9 = 998244353;
} // namespace zah233
using namespace zah233;

namespace hsh {
    std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> BDIST(0.1*mod1, 0.9*mod1);
    using H = AR<int, 2>;
    H makeC(char c) { return {c, c}; }
    const H base{BDIST(rng), BDIST(rng)};
    H operator+ (H l, H r) {
        F0R(i, 2) if ((l[i] += r[i]) >= mod1) l[i] -= mod1;
        return l; }
    H operator- (H l, H r) {
        F0R(i, 2) if ((l[i] -= r[i]) < 0) l[i] += mod1;
        return l; }
    H operator* (H l, H r) {
        F0R(i, 2) l[i] = ll(l[i]) * r[i] % mod1;
        return l; }
}
using namespace hsh;

struct segtree {
    int n;
    V<H> seg;
    segtree(int n_) {
        for (n=1; n < n_;) n*=2;
        seg.assign(n*2, H());
    }
    H cmb(H a, H b) { return a+b; }
    void pull(int p) { seg[p] = cmb(seg[p*2], seg[p*2+1]); }
    void upd(int x, H c) {
        seg[x+=n] = c;
        for (int i = x/2; i; i/=2) pull(i);
    }
    H qry(int lo, int hi) {
        H res{};
        for (int l=lo+n, r=hi+n; l<r; l/=2, r/=2) {
            if (l&1) res=res+seg[l++];
            if (r&1) res=res+seg[--r];
        }
        return res;
    }
};

H pows[200010];
int n, m;
str s;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> m;
    cin >> s;

    pows[0] = {1, 1};
    F0R(i, n) pows[i+1] = pows[i]*base;

    segtree frw(n), bak(n);
    F0R(i, n) {
        frw.upd(i, makeC(s[i])*pows[n-i-1]);
        bak.upd(i, makeC(s[i])*pows[i]);
    }
    rep(m) {
        int t; cin >> t;
        if (t==1) {
            int k; char x;
            cin >> k >> x;
            k--;
            frw.upd(k, makeC(x)*pows[n-k-1]);
            bak.upd(k, makeC(x)*pows[k]);
        } else {
            int a, b;
            cin >> a >> b;
            a--;
            H l = frw.qry(a, b) * pows[a];
            H r = bak.qry(a, b) * pows[n-b];
            cout << (l == r ? "YES\n" : "NO\n");
        }
    }

    return 0;
}

