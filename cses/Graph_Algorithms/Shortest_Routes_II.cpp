#include <bits/stdc++.h>
using namespace std;

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

const int N = 510;
ll dist[N][N];
int n, m, q;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> m >> q;
    F0R(i, n) F0R(j, n) dist[i][j] = (i == j ? 0 : 1e15);
    rep(m) {
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        dist[a][b] = dist[b][a] = min<ll>(dist[a][b], c);
    }
    F0R(k, n) F0R(i, n) F0R(j, n) {
        ckmin(dist[i][j], dist[i][k] + dist[k][j]);
    }
    rep(q) {
        int a, b; cin >> a >> b;
        a--, b--;
        ll ans = dist[a][b];
        if (ans == 1e15) ans = -1;
        cout << ans << '\n';
    }
    return 0;
}

