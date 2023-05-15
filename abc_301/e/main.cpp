// 標準ライブラリを全て読み込む
// 本書では細かく書きませんが、下記リンクが参考になります
// https://atcoder.jp/contests/apg4b/tasks/APG4b_af
#include <bits/stdc++.h>
// stdのstd::cinのような書き方ではなくcinと書けば良くなる
using namespace std;

// デバッグ用マクロ
// 本書では細かく書きませんが、下記リンクが参考になります
// https://naskya.net/post/0002/
#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

// データ構造の省略
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vpii = vector<pair<int, int>>;
using vpll = vector<pair<long long, long long>>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<long long>>;
using vvc = vector<vector<char>>;
using vvb = vector<vector<bool>>;
using vvvi = vector<vector<vector<int>>>;
// using pii = pair<int, int>;

// modの計算
long long mod1 = 1000000007;
long long mod2 = 998244353;

// 隣接グラフ(1 << 18は2^18で262144となる)
vector<ll> G[1 << 18];
// vector<ll> rG[1 << 18];

// ACL(AtCoder Library)、普段はコメントアウトしてある
#include <atcoder/all>
using namespace atcoder;

// repマクロ
// 0からn-1まで
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// aからb−1まで
#define rep3(i,a,b) for(int i=a;i<b;i++)
// n-1から0まで
#define per(i, n) for (int i = int(n) - 1; i >= int(0); i--)
// b-1からaまで
#define per3(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
// 範囲for文の省略
#define fore(i,a) for(auto &i:a)
// sort(A.begin(), A.end())をsort(all(A))のように書けます
#define all(x) (x).begin(), (x).end()

// 最大値と最小値の更新
// 返り値は更新した場合はtrue、そうでなければfalse
template <typename T>
inline bool chmax(T &a, T b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T>
inline bool chmin(T &a, T b) {
  return ((a > b) ? (a = b, true) : (false));
}

const int inf = 1000000000;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
// (si, sj) からの距離をテーブルにして返す
// 到達できないならば inf
vector<vector<int>> dist(int h, int w, const vector<string> &a, int si, int sj) {
    vector res(h, vector<int>(w, inf));
    res[si][sj] = 0;
    queue<pair<int, int>> q;
    q.emplace(si, sj);
    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (ni < 0 or ni >= h or nj < 0 or nj >= w) continue;
            if (a[ni][nj] == '#') continue;
            if (chmin(res[ni][nj], res[i][j] + 1)) q.emplace(ni, nj);
        }
    }
    return res;
}
int main() {
    int h, w, t;
    cin >> h >> w >> t;
    vector<string> a(h);
    int si, sj, gi, gj;
    vector<pair<int, int>> ls;
    for (int i = 0; i < h; i++) {
        cin >> a[i];
        for (int j = 0; j < w; j++) {
            if (a[i][j] == 'S') si = i, sj = j;
            if (a[i][j] == 'G') gi = i, gj = j;
            if (a[i][j] == 'o') ls.emplace_back(i, j);
        }
    }
    int cnt = ls.size();
    
    vector d(cnt, vector<vector<int>>()); // d[i] : i 個目のお菓子マスを始点とする距離テーブル
    for (int i = 0; i < cnt; i++) d[i] = dist(h, w, a, ls[i].first, ls[i].second);
    
    vector dp(1 << cnt, vector<int>(cnt, inf));
    for (int i = 0; i < cnt; i++) dp[1 << i][i] = d[i][si][sj];
    for (int s = 1; s < (1 << cnt); s++) {
        for (int last = 0; last < cnt; last++) {
            if (dp[s][last] == inf) continue;
            for (int nx = 0; nx < cnt; nx++) {
                if (s >> nx & 1) continue;
                chmin(dp[s | 1 << nx][nx], dp[s][last] + d[last][ls[nx].first][ls[nx].second]);
            }
        }
    }
    
    int ans = -1;
    if (dist(h, w, a, si, sj)[gi][gj] <= t) ans = 0;
    for (int s = 1; s < (1 << cnt); s++) {
        for (int last = 0; last < cnt; last++) {
            if (dp[s][last] + d[last][gi][gj] <= t) {
                int now = 0;
                for (int i = 0; i < cnt; i++) if (s >> i & 1) ++now;
                ans = max(ans, now);
            }
        }
    }
    cout << ans << endl;
}