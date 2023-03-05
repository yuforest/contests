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


ll X[20], Y[20], Z[20];

// 二点間の距離を計算する関数
ll dis(int x,int y) {
  return abs(X[x] - X[y]) + abs(Y[x] - Y[y]) + max(0LL, Z[y] - Z[x]);
}

ll f[17][1<<17];

// 距離の計算関数をいじった巡回セールスマン問題
int main() {
  ll N;
  cin >> N;
  rep(i, N) {
    cin >> X[i] >> Y[i] >> Z[i];
  }
  // 全ての値に大きな値を入れておく(あり得ない時間)
  for (int i=0;i<17;i++) {
    for (int j=0;j<(1<<17);j++) {
      f[i][j] = 1e18;
    }
  }
  // 現在地が原点で、訪問済みの街の集合がS
  f[0][0] = 0;
  // 状態数の全探索
  for (int j=0; j < (1 << N);j++) {
    // 現在地を全探索
    for (int i=0; i < N; i++) {
      // 経路がある時、既に訪問しているとき
      if (f[i][j] < 1e17) {
        // 現在地から次の訪問先への全探索
        // 既に訪問した都市をjという状態で持ち、現在地iからkに移動した時の時間を計算
        for (int k=0; k < N; k++) {
          // 移動後の値よりも現在地から移動した方が早ければ更新
          // debug(dis(i, k));
          if (f[i][j] + dis(i, k) < f[k][j|(1<<k)]) {
            f[k][j|(1<<k)] = f[i][j] + dis(i,k);
          }
        }
      }
    }
  }
  cout << f[0][(1 << N)-1] << endl;
}
