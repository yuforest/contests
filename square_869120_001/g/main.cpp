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
// vector<ll> G[1 << 18];

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

#define yes "Yes"
#define no "No"

// DPやlong longの最大値最小値更新で重宝します。
template <typename T>
inline bool chmax(T &a, T b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T>
inline bool chmin(T &a, T b) {
  return ((a > b) ? (a = b, true) : (false));
}

const ll INF = 1e16;
struct Edge {
    ll d;
    ll time;
};
Edge G[16][16];  // グラフ
ll N, M;
pair<ll, ll> dp[1 << 16][16];
// 一旦最後まで行って、そこからもど
pair<ll, ll> rec(ll S, ll v) {  // メモ化再帰
  // 全ての頂点を訪問した
  if (S == 0) {
    // 戻ってこれたらそこは距離0で1通りとなる
    if (v == 0) {
      return make_pair(0, 1);
    } else {
      // これは戻ってこれなかったので距離がINFで0通り
      return make_pair(INF, 0);
    }
  }
  // 現在訪問している頂点はすでに訪問済みの頂点である
  // このとき最短距離にならないので距離がINFで0通りを返す
  if ((S & (1 << v)) == 0) {  // Sに{v}が含まれていない
    return make_pair(INF, 0);
  }
  pair<ll, ll> &ret = dp[S][v];
  if (ret.first != 0) return ret;
  ret = make_pair(INF, 0);
  // それぞれの頂点を再帰的に訪問
  rep(u, N) {
    // 排他的論理和で訪問済み頂点のフラグを下げている、第二引数は訪問する頂点
    pair<ll, ll> p = rec(S ^ (1 << v), u);
    // 現在の時間にその辺を通るのに掛かる時間を足す
    p.first += G[u][v].d;
    // 制限時間以内に通れる時
    if (p.first <= G[u][v].time) {
      // 最短距離を更新
      if (ret.first > p.first) {
        ret = p;
      } else if (ret.first == p.first) {
        // 距離が同じ時は経路数を合わせる
        ret.second += p.second;
      }
    }
  }
  return ret;
}
int main() {
    cin >> N >> M;
    // グラフの初期化
    rep(i, 16) {
      rep(j, 16) {
        G[i][j].d = INF;
        G[i][j].time = 0;
      }
    }
    rep(i, M) {
      ll s, t, d, time;
      cin >> s >> t >> d >> time;
      s--, t--;
      // 双方向グラフ
      G[s][t].d = d;
      G[s][t].time = time;
      G[t][s].d = d;
      G[t][s].time = time;
    }
    // 状態を管理する変数(始点は訪問済みなので-1、そのほかは1のフラグ)と始点
    pair<ll, ll> ans = rec((1 << N) - 1, 0);
    if (ans.first != INF) {
      cout << ans.first << " " << ans.second << endl;
    } else {
      cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}