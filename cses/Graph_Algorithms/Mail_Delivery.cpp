#include <bits/stdc++.h>
namespace newbiezah {
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
#define ppb pop_back()
#define ppf pop_front()
#define pb push_back
#define pf push_front
#define eb emplace_back 
#define mp make_pair
#define ins insert
#define lb lower_bound
#define ub upper_bound
#define tcT template<class T

tcT> using V = std::vector<T>;
tcT> int ilb(V<T> &a, const T &b) { return int(lb(ALL(a), b) - a.begin()); }
tcT> int iub(V<T> &a, const T &b) { return int(ub(ALL(a), b) - a.begin()); }
tcT, size_t sz>
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
using VPL = V<pl>;

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

tcT> using pq = std::priority_queue<T>;
tcT> using pqg = std::priority_queue<T, std::vector<T>, std::greater<T>>;
tcT> bool ckmax(T &u, T v) { return v > u ? u = v, true : false; }
tcT> bool ckmin(T &u, T v) { return v < u ? u = v, true : false; }

#define FOR(i, a, n) for (int i = (a); i < (n); i++)
#define F0R(i, n) FOR(i, 0, n)
#define FORd(i, a, n) for (int i = (n) - 1; i >= (a); i--)
#define F0Rd(i, n) FORd(i, 0, n)
#define rep(n) F0R(_, n)
#define trav(a, v) for (auto &a : v)
#define each(a, b, v) for (auto &&[a, b] : v)
#define each3(a, b, c, v) for (auto &&[a, b, c] : v)

const char nl = '\n';
const int mod1 = int(1e9)+7, mod9 = 998244353;
const int dxi[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dyi[8] = {0, 1, 0, -1, 1, -1, 1, -1};
} // namespace newbiezah
using namespace newbiezah;
using namespace std;

const int N = 100010;
int n, m;
int eu[N*2], ev[N*2];
VI adj[N], ans;
bool used[N*2];

void dfs(int u=0) {
    while (SZ(adj[u])) {
        int i = adj[u].bk; adj[u].ppb;
        if (used[i]) continue;
        used[i] = 1;
        dfs(eu[i]^ev[i]^u);
        ans.pb(u);
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> m;
    F0R(i, m) {
        cin >> eu[i] >> ev[i];
        eu[i]--, ev[i]--;
        adj[eu[i]].pb(i);
        adj[ev[i]].pb(i);
    }
    F0R(i, n) {
        if (SZ(adj[i])&1) { cout << "IMPOSSIBLE\n"; exit(0); }
    }
    ans.pb(0);
    dfs();
    if (SZ(ans)^m+1) { cout << "IMPOSSIBLE\n"; exit(0); } 
    trav(a, ans) cout << a+1 << ' ';

    return 0;
}

