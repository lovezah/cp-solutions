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

template<size_t ASZ> struct AC {
    struct node {
        AR<int, ASZ> to; int lk;
        VI len;
    };
    V<node> d{{}};
    int ins(str s) {
        int u = 0;
        trav(C, s) {
            int c = C-'a';
            if (!d[u].to[c]) d[u].to[c]=SZ(d), d.eb();
            u = d[u].to[c];
        }
        d[u].len.pb(SZ(s));
        return u;
    }
    void ac() {
        d[0].lk = -1;
        queue<int> q; q.push(0);
        while (SZ(q)) {
            int u = q.ft; q.pop();
            F0R(c, ASZ) if (d[u].to[c]) {
                int v = d[u].to[c];
                d[v].lk = ~d[u].lk ? d[d[u].lk].to[c] : 0;
                q.push(v);
            }
            if (u) F0R(c, ASZ) if (!d[u].to[c]) {
                d[u].to[c] = d[d[u].lk].to[c];
            }
        }
        
        //FOR(i, 1, SZ(d)) adj[d[i].lk].pb(i);
        //dfs(0);
        VB vis(SZ(d)+2, 0);
        q.push(0); vis[0] = 1;
        while (SZ(q)) {
            int u = q.ft; q.pop();
            if (u) d[u].len.ins(d[u].len.end(), ALL(d[d[u].lk].len));
            F0R(c, ASZ) if (d[u].to[c]) {
                int v = d[u].to[c];
                if (!vis[v]) { q.push(d[u].to[c]); vis[v]=1; }
            }
        }
    }
};

const int N = 5050;
str s;
int n, dp[N];
void add(int &a, int b) {
    a = (ll(a)+b)%mod1;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> s >> n;
    AC<26> ac;
    rep(n) {
        str t; cin >> t;
        ac.ins(t);
    }
    ac.ac();
    dp[0] = 1;
    int u = 0;
    F0R(i, SZ(s)) {
        int c = s[i]-'a';
        u = ac.d[u].to[c];
        trav(l, ac.d[u].len) {
            if (i+1-l>=0) add(dp[i+1], dp[i+1-l]);
        }
    }
    cout << dp[SZ(s)] << '\n';
    return 0;
}
