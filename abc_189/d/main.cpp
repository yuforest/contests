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

ll dp[65][2];

int main() {
  int n; cin >> n;
  dp[0][0] = 1; // false の時
  dp[0][1] = 1; // true の時
  rep (i, n){
    string s;
    cin >> s;
    if (s == "AND") {
      // iとi+1を繋ぐ記号がANDであるとき、
      // 評価した結果が0になるためには、
      // 今0で次はどちらでも良い(2通り)
      // 今は1で次は必ず0になる(1通り)
      // なのでその和となる
      dp[i + 1][0] = dp[i][0] * 2 + dp[i][1];
      // 次の評価の結果が1になるためには、
      // 今1で次も1になる必要がある(1通り)
      dp[i + 1][1] = dp[i][1];
    } else {
      // iとi+1を繋ぐ記号がORである時、
      // 評価した結果が0になるためには、
      // 今0で次も0になる必要がある(1通り)
      dp[i + 1][0] = dp[i][0];
      // 評価した結果が1になるためには、
      // 今0で次は必ず1になる(1通り)
      // 今は1で次はどちらでもよい(2通り)
      // なのでその和になる
      dp[i + 1][1] = dp[i][0] + dp[i][1] * 2;
    }
  }
  debug(dp);
  // 最後はtrueになっている必要がある
  cout << dp[n][1] << endl;
  return 0;
}