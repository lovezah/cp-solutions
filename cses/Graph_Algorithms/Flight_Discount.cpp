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
VP adj1[N];
VP adj2[N];

VL dijkstra(int s, int t, VP adj[N]) {
    const ll INF = 2e16;
    VL dist(n, INF);
    dist[s] = 0;
    pqg<pl> qu;
    qu.emplace(0, s);
    while (!qu.empty()) {
        auto [exp, u] = qu.top(); qu.pop();
        if (exp != dist[u]) continue;
        each(v, w, adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                qu.emplace(dist[v], v);
            }
        }
    }
    return dist;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> m;
    rep(m) {
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        adj1[a].eb(b, c);
        adj2[b].eb(a, c);
    }
    VL dist1 = dijkstra(0, n-1, adj1);
    VL dist2 = dijkstra(n-1, 0, adj2);
    ll ans = dist1[n-1];
    F0R(i, n) {
        each(j, w, adj1[i]) {
            ckmin(ans, dist1[i]+dist2[j]+w/2);
        }
    }
    cout << ans << '\n';
    return 0;
}

