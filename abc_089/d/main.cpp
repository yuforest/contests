// ここは競プロではサボりがちです
#include <bits/stdc++.h>
using namespace std;

// デバッグ用マクロです。詳しくは https://naskya.net/post/0002/
#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

// 節操ないですが、競プロでは便利です。
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
using pii = pair<int, int>;

map<int, int> mp;
long long mod = 1000000007;
vector<ll> G[1 << 18];

// ACLです。使わない時はコメントアウトしています。導入方法はググってみてください。
// #include <atcoder/all>
// using namespace atcoder;

// 競プロerはrepマクロが大好き
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep3(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(), (x).end()

// 無くても困らない
#define INFTY (1 << 30)

// 浮動小数点の誤差を考慮した等式ですが、使わずに済むなら使わない方が確実です
#define EPS (1e-7)
#define equal(a, b) (fabs((a) - (b)) < EPS)

// DPやlong longの最大値最小値更新で重宝します。
template <typename T>
inline bool chmax(T &a, T b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T>
inline bool chmin(T &a, T b) {
  return ((a > b) ? (a = b, true) : (false));
}

// int main() {
//   ll H, W, D;
//   cin >> H >> W >> D;
//   vvl A(H, vl(W));
//   rep(i, H) rep(j, W) cin >> A[i][j];
//   map<ll, pair<ll, ll>> mp;
//   rep(i, H) rep(j, W) {
//     mp[A[i][j]] = {i, j};
//   }
//   debug(mp);
//   vvl dist(D);
//   rep(i, D) {
//     dist[i].push_back(0);
//   }
//   for(int i = 1; i <= D; i++) {
//     for(int j = i; j <= H*W; j+=D) {
//       if (i == j) continue;
//       auto p1 = mp[j];
//       auto p2 = mp[j-D];
//       ll d = abs(p1.first-p2.first) + abs(p1.second-p2.second);
//       dist[i%D].push_back(d);
//     }
//   }
//   debug(dist);
//   rep(i, D) {
//     rep(j, dist[i].size()-1) {
//       dist[i][j+1] += dist[i][j];
//     }
//   }
//   debug(dist);
//   ll Q;
//   cin >> Q;
//   rep(i, Q) {
//     ll l, r;
//     cin >> l >> r;
//     ll group = l % D;
//     debug(group);
//     l = (l-group) / D;
//     r = (r-group) / D;
//     if (group==0) {
//       l--;
//       r--;
//     }
//     debug(l);
//     debug(r);
//     cout << dist[group][r] - dist[group][l] << endl;
//   }
// }


// メモ化再帰でも解ける
// int H, W, D, A[303][303], Q;
// pair<int, int> idx[90101];
// int memo[90101];
// int f(int x) {
//   if (0 < memo[x]) return memo[x];
//   // これ以上小さくできないので0
//   // 例えばD=3でx=0,1,2の時はこれ以上小さくできないので0
//   // 1や2に到達するコストは0ということになる
//   if (x < D) return 0;

//   int y = x - D;
//   int cost = abs(idx[x].first - idx[y].first) + abs(idx[x].second - idx[y].second);
//   // 前から今のところに到達するコスト+最初から前のところまで到達するコストを再帰的に求める
//   int res = cost + f(y);
//   return memo[x] = res;
// }
// int main() {
//     cin >> H >> W >> D;
//     rep(y, H) rep(x, W) {
//       cin >> A[y][x];
//       // 0-indexedにしている
//       A[y][x]--;
//       idx[A[y][x]] = make_pair(x, y);
//     }
//     cin >> Q;
//     rep(q, Q) {
//       int L, R; cin >> L >> R;
//       L--; R--;
//       int ans = f(R) - f(L);
//       printf("%d\n", ans);
//     }
// }


// もっと簡単に一次元配列を使っても解くことができる
int H, W, D, A;
int Q, L, R;
int px[90001], py[90001];
int d[90001];
int main() {
  scanf ("%d %d %d", &H, &W, &D);
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      scanf ("%d", &A);
      // 座標を記録
      px[A] = i , py[A] = j;
    }
  }
  // ここまで到達するためのコストを累積和的に計算
  for (int i = D+1; i <= H * W ; i++) {
    d[i] = d[i-D] + abs(px[i]-px[i-D]) + abs(py[i]-py[i-D]);
  }
  scanf ("%d", &Q);
  while (Q--) {
    scanf ("%d %d", &L, &R);
    printf ("%d\n" , d[R]-d[L]);
  }
}