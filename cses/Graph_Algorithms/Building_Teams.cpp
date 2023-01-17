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

const int N = 100010;
int n, m;
VI adj[N];
int w[N];

bool dfs(int u, int par, int c) {
    w[u] = c;
    trav(v, adj[u]) if (v != par) {
        if (w[v] != -1) {
            if (w[v] == w[u]) return 0;
        } else if (!dfs(v, u, 3-c)) return 0;
    }
    return 1;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    rep(m) {
        int a, b; cin >> a >> b;
        a--, b--;
        assert(a >= 0 && a < n);
        assert(b >= 0 && b < n);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    F0R(i, n) w[i] = -1;
    F0R(i, n) {
        if (w[i] < 0) {
            if (!dfs(i, -1, 1)) {
                cout << "IMPOSSIBLE\n";
                exit(0);
            }
        }
    }
    F0R(i, n) cout << w[i] << ' ';
    return 0;
}

