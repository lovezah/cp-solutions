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

const int N = 1010;
char g[N][N];
int n, m, vis[N][N], pre[N][N];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
str mv = "DRUL";

int valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && g[x][y] != '#' && !vis[x][y];
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> m;;
    F0R(i, n) F0R(j, m) pre[i][j] = -1;
    F0R(i, n) cin >> g[i];
    int sx, sy;
    F0R(i, n) F0R(j, m) if (g[i][j] == 'A') sx = i, sy = j;

    VP que = {{sx, sy}};
    vis[sx][sy] = 1;
    F0R(i, SZ(que)) {
        auto [x, y] = que[i];
        //dbg(x, y);
        if (g[x][y] == 'B') {
            str ans;
            while (g[x][y] != 'A') {
                int t = pre[x][y];
                ans.pb(mv[t]);
                x -= dx[t], y -= dy[t];
            }
            REV(ans);
            cout << "YES\n";
            cout << SZ(ans) << '\n';
            cout << ans << '\n';
            exit(0);
        }
        F0R(j, 4) {
            int nx = x + dx[j], ny = y + dy[j];
            if (valid(nx, ny)) {
                vis[nx][ny] = 1;
                pre[nx][ny] = j;
                que.pb({nx, ny});
            }
        }
    }
    cout << "NO\n";
    return 0;
}

