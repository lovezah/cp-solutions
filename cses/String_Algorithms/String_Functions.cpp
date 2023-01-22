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

const int N = 1000010;
VI getZ(str s) {
    int n = SZ(s), L = 1, R = 0; s += "#";
    VI z(n); z[0] = 0;
    FOR(i, 1, n) {
        if (i <= R) z[i] = min(R-i+1, z[i-L]);
        while (s[z[i]] == s[i+z[i]]) ++z[i];
        if (i+z[i]-1 > R) R = i+z[i]-1, L = i;
    }
    return z;
}
VI kmp(str s) {
    int n = SZ(s);
    VI f(n+1); f[0] = -1;
    FOR(i, 1, n+1) {
        for (f[i]=f[i-1]; ~f[i]&&s[f[i]]!=s[i-1];) f[i] = f[f[i]];
        ++f[i];
    }
    return f;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    str s;
    cin >> s;
    VI z = getZ(s);
    trav(a, z) cout << a << ' ';
    cout << nl;
    VI f = kmp(s);
    F0R(i, SZ(s)) cout << f[i+1] << ' ';
    cout << nl;
    return 0;
}

