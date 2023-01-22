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

const int N = 1000010, MOD = int(1e9)+7;
using H = AR<int, 2>;
uniform_int_distribution<int> BDIST(0.1*MOD, 0.9*MOD);
const H base{BDIST(rng), BDIST(rng)};
H operator+ (H l, H r) {
    F0R(i, 2) if ((l[i] += r[i]) >= MOD) l[i] -= MOD;
    return l;
}
H operator- (H l, H r) {
    F0R(i, 2) if ((l[i] -= r[i]) < 0) l[i] += MOD;
    return l;
}
H operator* (H l, H r) {
    F0R(i, 2) l[i] = ll(l[i]) * r[i] % MOD;
    return l;
}

H hs[N], pw[N];
str s;
H h(int i, int j) {
    return hs[j] - hs[i] * pw[j-i];
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> s; int n = SZ(s);
    pw[0] = {1, 1};
    F0R(i, n) {
        pw[i+1] = pw[i] * base;
        hs[i+1] = hs[i] * base + H{s[i], s[i]};
    }
    F0R(i, n) {
        H hsh = h(0, i+1);
        bool ok = 1;
        for (int j = i+1; j<n && ok; j += i+1) {
            if (j+i < n) ok &= (hsh == h(j, j+i+1));
            else ok &= (h(j, n) == h(0, n-j));
        }
        if (ok) cout << i+1 << ' ';
    }
}
