#include <bits/stdc++.h>

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
    
using ll = int64_t;
using db = double;
using str = std::string;
using pi = std::pair<int, int>;
using pl = std::pair<ll, ll>;
using VI = std::vector<int>;
using VL = std::vector<ll>;
using VS = std::vector<str>;
using VB = std::vector<bool>;
using VP = std::vector<pi>;
template<class T, size_t sz>
using AR = std::array<T, sz>;

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

const int N = 250010, mod = int(1e9)+7;
int dp[N], n;

void add(int &a, int b) {
    a = (ll(a) + b) % mod;
}
int pow(int a, int k) {
    int ret = 1;
    while (k) {
        if (k&1) ret = ll(ret) * a % mod;
        k /= 2;
        a = ll(a) * a % mod;
    }
    return ret % mod;
}
int mul(int a, int b) {
    a %= mod; b %= mod;
    if (a < 0) a += mod;
    if (b < 0) b += mod;
    return (ll(a) * b) % mod;
}
int main() {
    using namespace std;
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n;
    int s = n * (n+1) / 2;
    if (s & 1) {
        cout << "0\n";
        exit(0);
    }
    s /= 2;
    dp[0] = 1;
    FOR(i, 1, n+1) {
        for (int j = s; j >= i; j--)
            add(dp[j], dp[j-i]);
    }
    int ans = mul(dp[s], pow(2, mod-2));
    cout << ans << '\n';
    return 0;
}

