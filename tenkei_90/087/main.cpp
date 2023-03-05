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
#define per3(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) per3(i, 0, b)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(), (x).end()

// 無くても困らない
#define INFTY (1 << 30)

// 浮動小数点の誤差を考慮した等式ですが、使わずに済むなら使わない方が確実です
#define EPS (1e-7)#define equal(a, b) (fabs((a) - (b)) < EPS)

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

long long N, P, K, A[69][69];
long long dist[69][69];

// ワーシャルフロイド法で、Xをlensとした時にP以下で到達できる経路の組をカウント
int count_number(long long lens) {
  // 距離を初期化
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (A[i][j] == -1) dist[i][j] = lens;
      if (A[i][j] != -1) dist[i][j] = A[i][j];
    }
  }
  // ワーシャルフロイド法
  // kを経由することで、iからjへの距離が短くなる場合は更新
  for (int k = 1; k <= N; k++) {
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }
  }
  int cnt = 0;
  // 距離がP以下の経路の組をカウント
  for (int i = 1; i <= N; i++) {
    for (int j = i + 1; j <= N; j++) {
      if (dist[i][j] <= P) cnt++;
    }
  }
  return cnt;
}

// f(x) = 最短距離がP以下の頂点対の個数
// 二分探索で、f(x)<=cntsとなる最小のxを求める
long long get_border(long long cnts) {
  long long cl = 1, cr = 5000000000LL, cm, minx = 5000000000LL;
  for (int i = 0; i < 40; i++) {
    cm = (cl + cr) / 2LL;
    // Xをcmとした時にP以下で到達できる経路の組の数
    int res = count_number(cm);
    // これがcnts以下なら右側をずらしてcr以下を探索
    // cm以下にf(x)<=cntsとなる最小のxがある
    if (res <= cnts) { cr = cm; minx = min(minx, cm); }
    else { cl = cm; }
  }
  return minx;
}

int main() {
  cin >> N >> P >> K;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) cin >> A[i][j];
  }

  // f(x)<=Kとなる最小のxをLとする
  // f(x)<Kとなる最小のxをRとする(つまりf(x)<=K-1の時)
  // RはK-1個以上の経路の組がある時の最小のxなので条件がゆるくなり答えは大きくなる
  // その時求める答えはR-Lである(L, L+1, ..., R-1までが条件を満たす)
  // Rが非常に大きくなる時、K-1ならばXをどのように選んでも、Pスヌーク
  // 以下で到達できる経路はK-1個より多くあるので、R-Lは無限大になる
  // R,Lともに非常に大きい時は、Xをどのように選んでも、Pスヌーク
  // 以下で到達できる経路はK個より多くあるので、R-Lは0となる
  long long L = get_border(K);
  long long R = get_border(K - 1);
  debug(L);
  debug(R);
  if (R - L >= 2000000000LL) cout << "Infinity" << endl;
  // 経路の組がK個以上ある場合は、LとRの差を出力
  else cout << R - L << endl;
  return 0;
}