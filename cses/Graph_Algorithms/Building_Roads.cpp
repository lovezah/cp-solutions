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

struct Union_Find {
    int n;
    VI par;
    Union_Find(int n_) : n(n_), par(n, -1) {}
    int get_par(int a) {
        while (par[a] >= 0) {
            if (par[par[a]] >= 0) par[a] = par[par[a]];
            a = par[a];
        }
        return a;
    }
    bool join(int a, int b) {
        a = get_par(a), b = get_par(b);
        if (a == b) return false;
        if (par[a] > par[b]) swap(a, b);
        par[a] += par[b];
        par[b] = a;
        return true;
    }
};

int n, m;
VI comp[100010];
VI ans;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> m;

    Union_Find UF(n);
    rep(m) {
        int x, y; cin >> x >> y;
        x--, y--;
        UF.join(x, y);
    }
    F0R(i, n) {
        int pi = UF.get_par(i);
        if (pi == i) ans.pb(i);
        comp[pi].pb(i);
    }

    cout << SZ(ans)-1 << '\n';
    FOR(i, 1, SZ(ans)) {
        cout << ans[0]+1 << ' ' << ans[i]+1 << '\n';
    }

    return 0;
}

