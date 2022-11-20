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

int n,m;
double f[18][1<<18];
using pp=pair<int,int>;
pp a[20];
double sqr(double x) {
  return x*x;
}
// 二点間の距離を計算する関数
double dis(int x,int y) {
  return sqrt(sqr(a[x].first-a[y].first) + sqr(a[x].second-a[y].second));
}

// 巡回セールスマン問題の亜種
// 制約が小さいグラフで全ての都市を回るような問題はbitDPを疑う(この問題はN+M=17)
int main() {
  cin >> n >> m;
  // 街と宝箱はまとめてaに入れておく、i=0の時は原点としているので1から
  for (int i = 1; i <= n+m; i++) cin >> a[i].first >> a[i].second;
  // 全ての値に大きな値を入れておく(あり得ない時間)
  for (int i=0;i<18;i++) {
    for (int j=0;j<(1<<18);j++) {
      f[i][j]=1e18;
    }
  }
  // 現在地が原点で、訪問済みの街の集合がS
  f[0][0] = 0;
  // 状態の全探索(状態をbitとして持っている)
  // 既にいくつかの都市を訪問した状態から考える
  for (int j=0;j < (1 << n+m+1);j++) {
    // 現在地を全探索
    for (int i=0; i <= n + m; i++) {
      // 経路がある時、既に訪問しているとき
      if (f[i][j] < 1e18) {
        int cnt = 0;
        // 宝箱を訪問している数をカウントしている
        // n+1からn+mまで全探索
        // 現在の状態をkだけ右シフトしたところにフラグが立っていればインクリメント
        for (int k=n+1; k<=n+m ;k++) if (j>>k & 1) cnt++;

        // 2^cntを計算
        int sp = 1 << cnt;
        // 現在地から次の訪問先への全探索
        // 既に訪問した都市をjという状態で持ち、現在地iからkに移動した時の時間を計算
        for (int k=0; k<=n+m; k++) {
          // 移動後の値よりも現在地から移動した方が早ければ更新
          if (f[i][j]+dis(i,k)/sp < f[k][j|(1<<k)]) {
            f[k][j|(1<<k)] = f[i][j] + dis(i,k)/sp;
          }
        }
      }
    }
  }
  double ans = 1e18;
  // 最小値を更新
  // 宝物部分を全探索
  for (int j=0; j < (1<<m); j++) {
    // 宝物をn+1だけ左シフトしたものと全て訪問した状態の和の状態
    int k = (j << n+1) | ((1<<n+1)-1);
    ans = min(ans, f[0][k]);
  }
  cout << fixed << setprecision(8) << ans << endl;
  return 0;
}