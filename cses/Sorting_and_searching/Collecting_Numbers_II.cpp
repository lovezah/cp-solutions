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

int main() {
    using namespace std;
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M; cin >> N >> M;
    VI A(N); trav(a, A) cin >> a;
    VI seen(N + 1, 0);
    int ans = 0;
    F0R(i, N) {
        if (!seen[A[i]-1]) ans++;
        seen[A[i]] = 1;
    }
    VI pos(N + 1);
    F0R(i, N) pos[A[i]] = i;
    rep(M) {
        int a, b; cin >> a >> b;
        a--, b--;
        int x = A[a], y = A[b];
        if (x-1 >= 1 && b <= pos[x-1] && pos[x-1] <= a) ans++;
        if (x-1 >= 1 && a <= pos[x-1] && pos[x-1] <= b) ans--;
        if (x+1 <= N && a <= pos[x+1] && pos[x+1] <= b) ans++;
        if (x+1 <= N && b <= pos[x+1] && pos[x+1] <= a) ans--;

        if (y-1 >= 1 && a <= pos[y-1] && pos[y-1] <= b) ans++;
        if (y-1 >= 1 && b <= pos[y-1] && pos[y-1] <= a) ans--;
        if (y+1 <= N && b <= pos[y+1] && pos[y+1] <= a) ans++;
        if (y+1 <= N && a <= pos[y+1] && pos[y+1] <= b) ans--;
        if (a < b && x == y + 1) ans++;
        if (a < b && x == y - 1) ans--;
        if (a > b && x == y - 1) ans++;
        if (a > b && x == y + 1) ans--;
        pos[x] = b; pos[y] = a;
        swap(A[a], A[b]);
        cout << ans << '\n';
    }
    return 0;
}

