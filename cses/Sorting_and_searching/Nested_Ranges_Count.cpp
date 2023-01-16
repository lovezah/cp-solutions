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
int n, sz;
std::vector<AR<int, 3>> p;
int ans1[N], ans2[N];
VI all;
int get(int x) {
    return int(lb(ALL(all), x) - all.begin()) + 1;
}

ll c1[N*2];
void add1(int x) {
    for (int i = x; i <= sz; i += i & -i)
        c1[i] += 1;
}
ll query1(int x) {
    ll ret = 0;
    for (int i = x; i; i -= i & -i)
        ret += c1[i];
    return ret;
}

ll c2[N*2];
void add2(int x) {
    for (int i = x; i <= sz; i += i & -i)
        c2[i] += 1;
}
ll query2(int x) {
    ll ret = 0;
    for (int i = x; i; i -= i & -i)
        ret += c2[i];
    return ret;
}
int main() {
    using namespace std;
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n;
    F0R(i, n) {
        int a, b; cin >> a >> b;
        p.pb(AR<int, 3>{a, b, i});
        all.pb(a), all.pb(b);
    }
    UNIQUE(all);
    sz = SZ(all);
    F0R(i, n) p[i] = AR<int, 3>{get(p[i][0]), get(p[i][1]), i};
    sort(ALL(p));
    int j = n-1;
    F0Rd(i, n) {
        while (j >= 0 && p[j][0] >= p[i][0]) {
            add1(p[j][1]);
            j--;
        }
        ans1[p[i][2]] = query1(p[i][1])-1;
    }
    F0R(i, n) cout << ans1[i] << " \n"[i+1==n];

    j = 0;
    F0R(i, n) {
        while (j < n && p[j][0] <= p[i][0]) {
            add2(p[j][1]);
            j++;
        }
        ans2[p[i][2]] = query2(sz)-query2(p[i][1]-1)- 1;
    }
    F0R(i, n) cout << ans2[i] << " \n"[i+1==n];
    return 0;
}

