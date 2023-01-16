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

const int N = 200010;
int n, k = 1;
int c[N];

void add(int x, int t) {
    for (int i = x; i <= n; i += i & -i)
        c[i] += t;
}
int query(int x) {
    int ret = 0;
    for (int i = x; i; i -= i & -i)
        ret += c[i];
    return ret;
}
int range(int l, int r) {
    return query(r) - query(l-1);
}
int search(int l, int r, int s) {
    int lo = l, hi = r;
    while (lo < hi) {
        int mi = (lo + hi) / 2;
        if (range(l, mi) < s) lo = mi + 1;
        else hi = mi;
    }
    return lo;
}
int main() {
    using namespace std;
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++)
        add(i, 1);
    int p = 1;
    for (int i = n; i >= 1; i--) {
        int k1 = (k % i) + 1;
        int tot = range(p, n);
        if (tot >= k1) {
            p = search(p, n, k1);
        } else {
            p = search(1, n, k1-tot);
        }
        add(p, -1);
        cout << p << " \n"[i==1];
        p++; if (p > n) p = 1;
    }
}
