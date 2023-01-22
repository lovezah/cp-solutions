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

namespace hashing{
    std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    const int MOD = int(1e9)+7;
    using H = std::array<int, 2>;
    H makeH(char c) { return {c, c}; }
    uniform_int_distribution<int> BDIST(0.1*MOD, 0.9*MOD);
    const H base{BDIST(rng), BDIST(rng)};
    H operator+ (H l, H r) {
        for (int i = 0; i < 2; i++) if ((l[i] += r[i]) >= MOD) l[i] -= MOD;
        return l;
    }
    H operator- (H l, H r) {
        for (int i = 0; i < 2; i++) if ((l[i] -= r[i]) < 0) l[i] += MOD;
        return l;
    }
    H operator* (H l, H r) {
        for (int i = 0; i < 2; i++) l[i] = int64_t(l[i]) * r[i] % MOD;
        return l;
    }
    // H& operator+= (H& l, H r) { return l = l+r; }
    // H& operator-= (H& l, H r) { return l = l-r; }
    // H& operator*= (H& l, H r) { return l = l*r; }

    struct hashRange {
        std::string s;
        std::vector<H> cum {{}}, pows{{1, 1}};
        void add(char c) { s += c; cum.push_back(base*cum.back()+makeH(c)); }
        void add(std::string t) { for (auto ch : t) add(ch); }
        void extend(int len) { 
            while (int(pows.size()) <= len)
                pows.push_back(base*pows.back());
        }
        H hash(int l, int r) {
            int len = r - l; extend(len);
            return cum[r] - cum[l] * pows[len];
        }
    };
} // namespace hashing
using namespace hashing;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    str s;
    cin >> s; int n = SZ(s);
    hashRange hasher;
    hasher.add(s);
    VI ans;
    FOR(i, 1, n) {
        if (hasher.hash(0, i) == hasher.hash(n-i, n)) ans.pb(i);
    }
    trav(a, ans) cout << a << ' ';
    return 0;
}

