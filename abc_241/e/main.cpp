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

// f(i) = (i+Ai)modN
// Kは2の累乗の合計として表すことができる
// K=2^c1+2^c2+...+2^ck(0<=c1<c2<...<ck)
// 求めたいのはK項からなる
// A0+Af(0)+...+Af^(K-1)(0)
// これを手前から2^c1項、2^c2項、...最後の2^ck項と分けることで
// dp[c1][0]+dp[c2][s1]+dp[c3][s2]+...+dp[ck][sk-1]と求めることができる
// siは(A0+Af(0)+...+Af(2^c1+2^c2+...+2^(ci-1)-1)(0))%N

long long a[200010];
// 2^i回合成したもの
long long dp[40][200010];


// ダブリンぐ
int main() {
  int n;
  long long k;
  long long ans;
  cin >> n >> k;
  for (int i = 0; i < n; i++)cin >> a[i];

  // 初期値セット、aの配列をそのまま入れる
  // 2^0=1回だけ繰り返したとき
  for (int j = 0; j < n; j++) dp[0][j] = a[j];

  // 2^0,2^1...2^38回まで操作を繰り返した時の合計のアメの数を
  // 前計算しておく
  // jを起点として、2^iだけ操作を繰り返した時の値がdp[i+1][j]となる
  for (int i = 0; i < 39; i++) {
    for (int j = 0; j < n; j++) {
      // 前半の2^i項と後半の2^i項に分けている
      // dp[i][j]はこれまでの2^i回
      // dp[i][(j+dp[i][j]) % n]は
      // 次の位置を起点として2^i回移動した後の合計の数
      // これを足すことでjを起点として2^(i+1)移動した後の合計数を
      // 求めることができる
      // (j+dp[i][j]) % nはjからdp[i][j]だけ値が増えた後に行くインデックスを表す
      dp[i + 1][j] = dp[i][j] + dp[i][(j+dp[i][j]) % n];
      if (i<5) {
        debug(i);
        debug(dp[i+1][j]);
        debug(dp[i][j]);
        debug(dp[i][(j+dp[i][j]) % n]);
      }
    }
  }
  // 皿の中に入っているアメの数
  ans = 0;
  for (int i = 0; i < 40; i++) {
    // bitがたっていたら答えに追加
    if (k & 1) {
      ans += dp[i][ans%n];
    }
    // kを右シフト
    k = (k >> 1);
  }
  cout << ans << endl;
  return 0;
}