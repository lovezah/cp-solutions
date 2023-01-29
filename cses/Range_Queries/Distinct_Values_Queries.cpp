#include <bits/stdc++.h>
using namespace std;
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
#define pb push_back
#define eb emplace_back 
#define mp make_pair
#define ins insert
#define lb lower_bound
#define ub upper_bound
#define tcT template<class T

tcT> using V = std::vector<T>;
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
const int mod1 = int(1e9)+7;
const int mod9 = 998244353;
} // namespace newbiezah
using namespace newbiezah;

const int N = 200010;
int n, q;
int a[N], freq[N], ans[N], res=0;
V<AR<int, 3>> qry;
VI all;

void add(int v) {
    if (++freq[v]==1) res++;
}
void del(int v) {
    if (freq[v]--==1) res--;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> q;
    F0R(i, n) cin >> a[i+1], all.pb(a[i+1]);
    UNIQUE(all);
    F0R(i, n) a[i+1] = int(lb(ALL(all), a[i+1])-all.begin());

    F0R(i, q) {
        int l, r; cin >> l >> r;
        qry.pb({l, r, i});
    }

    const int M = 500;
    sort(ALL(qry), [](auto x, auto y) {
        if (x[0]/M == y[0]/M) return x[1] < y[1];
        return x[0]/M < y[0]/M;
    });
    int L = 1, R = 0;
    each3(l, r, id, qry) {
        while (R < r) ++R, add(a[R]);
        while (L > l) --L, add(a[L]);
        while (R > r) del(a[R]), --R;
        while (L < l) del(a[L]), ++L;
        ans[id] = res;
    }
    F0R(i, q) cout << ans[i] << nl;
    return 0;
}

