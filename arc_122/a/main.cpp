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
#include <atcoder/all>
using namespace atcoder;

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

const ll MOD = 1000000007;

int n;
ll arr[100002];
// 0がプラス、1がマイナス
ll cnt[100002][2];
ll dp[100002][2];

int main(){
  scanf("%d", &n);
  for(int i=1; i<=n; i++){
      scanf("%lld", &arr[i]);
  }
  // 1つめまで選んだ時に最後がプラスであるような数の合計
  // 1つめではマイナスのことは考えなくて良い
  dp[1][0] = arr[1];
  // 通り数をカウントする配列
  cnt[1][0] = 1;

  // i番目の数字を選ぶ時に、マイナスかプラスかは異なるが足し引きされる数字は全て同じ
  // よってそこで足し引きされうる式の数を、プラスとマイナスで分けて記録しておけば良い
  for(int i=2; i<=n; i++){
    // 今回がプラス
    // 一つ前の値に今の値に通り数を掛けたものを足してmodを取る
    dp[i][0] = (dp[i-1][0] + dp[i-1][1] + arr[i] * (cnt[i-1][0] + cnt[i-1][1])) % MOD;
    // 今回がマイナス
    // マイナスは2回連続できないのでdp[i-1][1]からの遷移がない
    dp[i][1] = (dp[i-1][0] + MOD - arr[i] * cnt[i-1][0] % MOD) % MOD;
    // 今回プラスなのは前回マイナスと前回マイナスを足したもの
    cnt[i][0] = (cnt[i-1][0] + cnt[i-1][1]) % MOD;
    // 今回マイナスなのは前回プラスの時のみ
    cnt[i][1] = cnt[i-1][0];
  }
  cout <<  (dp[n][0] + dp[n][1]) % MOD << endl;
}