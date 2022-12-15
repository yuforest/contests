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

const int MAXN = 55;
int v[MAXN][MAXN], sum[MAXN][MAXN];
int dp[MAXN*MAXN];

int main(){
  int N;
  cin >> N;
  // 入力を受け取る
  vector<vector<int>> v(N, vector<int>(N));
  rep(i, N) rep(j, N) cin >> v[i][j];

  // 二次元累積和の計算
  rep3(i, 1, N + 1) rep3(j, 1, N + 1) {
    // 今の値に縦の1つ前の累積和と横の1つ前の累積和を足して、横縦共に1つ前の累積和を引く
    sum[i][j] = v[i - 1][j - 1] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
  }
  // 下記のようなものができる
  // 元の配列
  // 3 2 1
  // 2 2 1
  // 1 1 1
  // 累積和
  // 3 5 6
  // 5 9 11
  // 6 11 14

  debug(sum);

  // dp配列に焼ける = 長方形の大きさに対する美味しさの合計の最大値を保存しておく
  // O(N^4)=6250000
  // 右下の位置と左上の位置を全探索i,jが右下、k,lが左上の一つ前(範囲に含まない)
  rep3(i, 1, N + 1) rep3(j, 1, N + 1) rep3(k, 0, i) rep3(l, 0, j){
    // 指定された長方形に対する美味しさの合計を返す
    int s = sum[i][j] - sum[i][l] - sum[k][j] + sum[k][l];
    // 最大値を更新
    // (i - k)*(j - l)で長方形の大きさを計算できる
    dp[(i - k)*(j - l)] = max(dp[(i - k)*(j - l)], s);
  }

  // 上限が小さくても最大値が大きいものがあれば、大きいものを更新していく
  rep(i, MAXN*MAXN - 1) dp[i + 1] = max(dp[i + 1], dp[i]);

  int Q;
  cin >> Q;
  while (Q--){
    int p;
    cin >> p;
    // 前計算してあるので答えをO(1)で取得可能
    cout << dp[p] << endl;
  }


  return 0;
}