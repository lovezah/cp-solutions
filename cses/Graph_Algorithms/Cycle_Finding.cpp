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
}
using namespace zah339;

const int N = 2510;
const ll INF = 2e16;
int n, m;
VP adj[N];
ll dist[N];
int pre[N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> m;
    rep(m) {
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        adj[a].eb(b, c);
    }
    F0R(i, n) pre[i] = -1;
    int x;
    F0R(z, n) {
        x = -1;
        F0R(u, n) {
            each(v, w, adj[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pre[v] = u;
                    x = v;
                }
            }
        }
    }
    if (x == -1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        F0R(i, n) x = pre[x];
        VI ans;
        int y = x;
        ans.pb(y);
        y = pre[y];
        while (y ^ x) {
            ans.pb(y);
            y = pre[y];
        }
        ans.pb(x);
        REV(ans);
        trav(a, ans) cout << a+1 << ' ';
    }
}
