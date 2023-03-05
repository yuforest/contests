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

// DPやlong longの最大値最小値更新で重宝します。
template <typename T>
inline bool chmax(T &a, T b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T>
inline bool chmin(T &a, T b) {
  return ((a > b) ? (a = b, true) : (false));
}

// int D, G, P[10], C[10];
// int dp[11][401010];
// int inf = 1e9;

// int main() {
//   cin >> D >> G;
//   rep(i, D) cin >> P[i] >> C[i];

//   // 1/100にしておく
//   G /= 100;
//   rep(i, D) C[i] /= 100;

//   // 初期化
//   rep(i, D + 1) rep(point, 201010) dp[i][point] = inf;
//   // dp[i][point] := i番目の問題まででpoint点得るための最小問題数
//   dp[0][0] = 0;

//   // 点数とポイントで全探索
//   rep(i, D) rep(point, 201010) {
//     // 各ポイントにつき問題数は最大100問
//     // i+1点の問題を1~P[i]問解いた時のポイントごとの最小問題数
//     // 今までの最小問題数に加えて、今回の問題数を足す
//     rep(j, P[i]) chmin(dp[i + 1][point + (i + 1)*j], dp[i][point] + j);
//     // i+1点の問題を全問解いた時のポイントの最小問題数を更新
//     chmin(dp[i + 1][point + (i + 1)*P[i] + C[i]], dp[i][point] + P[i]);
//   }

//   int ans = inf;
//   // G点以上の最小問題数を探す
//   rep3(point, G, 201010) chmin(ans, dp[D][point]);
//   cout << ans << endl;
// }


// O(2^D*D)
int main(){
  int D, G, p[11], c[11];
  cin >> D >> G;
  for(int i = 0; i < D; ++i){
    cin >> p[i] >> c[i];
  }

  int ans = 1e9;
  // 完全に解く問題をbit全探索,2^10=1024
  for(int mask = 0; mask < (1 << D); ++mask){
    int s = 0, num = 0, rest_max = -1;
    // Dを全探索
    for(int i = 0; i < D; ++i){
      if(mask >> i & 1){
        // 合計得点を計算
        s += 100 * (i+1) * p[i] + c[i];
        // 問題数を計算
        num += p[i];
      }else{
        // 全部解かない問題の中で最も得点の高いものを記録
        rest_max = i;
      }
    }
    // 合計値がGより小さければ、最も得点の高い問題を解く
    if(s < G){
      // 1問あたりの得点
      int s1 = 100 * (rest_max + 1);
      // 必要な問題数
      int need = (G - s + s1 - 1) / s1;
      // 必要な問題数が解ける問題数より多い場合は無理
      if(need >= p[rest_max]){
        continue;
      }
      // 必要な問題数を加算
      num += need;
    }
    // 最小値を更新
    ans = min(ans, num);
  }
  cout << ans << endl;
}