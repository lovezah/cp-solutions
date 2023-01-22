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

str s, t;

std::vector<int> kmp(std::string s) {
    // f[i] (1-index) the longest matching length
    // when f[i] > 0 : s[i-f[i]+1]...s[i] == s[0]...s[f[i]-1]
    // s (0-index) 
    int n = int(s.size());
    std::vector<int> f(n+1); f[0] = -1;
    for (int i = 1; i <= n; i++) {
        for (f[i] = f[i-1]; ~f[i] && s[f[i]] != s[i-1];) f[i] = f[f[i]];
        f[i]++;
    }
    return f;
}
std::vector<int> findOcc(std::string t, std::string s) {
    // find all occurrences of t in s
    std::vector<int> f = kmp(t + "@" + s), res;
    int n = int(t.size()), m = int(s.size());
    for (int i = n+1; i <= m+1; i++) {
        if (f[i+n] == n) res.push_back(i-n-1);
    }
    return res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> s >> t;
    VI occ = findOcc(t, s);
    cout << SZ(occ) << '\n';
    return 0;
}

