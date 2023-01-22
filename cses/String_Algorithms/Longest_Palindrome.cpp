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

std::vector<int> manacher(std::string _s) {
    std::string s = "$#";
    for (auto ch : _s) s += ch, s += "#";
    s += "@";
    int n = int(s.size()), mid, hi = 0;
    std::vector<int> f(n+1); // "$#a#b#a#@", centered on b, f[b] = 4
    for (int i = 1; i < n; i++) {
        if (i <= hi) f[i] = std::min(f[2*mid-i], hi-i+1);
        else f[i] = 1;
        while (s[i-f[i]] == s[i+f[i]]) ++f[i];
        if (i+f[i]-1 > hi) hi = i+f[i]-1, mid = i;
    }
    return f;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    str s; cin >> s;
    VI f = manacher(s);
    int n = SZ(f);
    int p = 1;
    for (int i = 1; i < n; i++) {
        if (ckmax(f[p], f[i])) p = i;
    }
    int t = (p-f[p]+1)/2;
    for (int i = t; i < t+f[p]-1; i++)
        cout << s[i];
    return 0;
}

