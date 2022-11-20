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

const int64_t MOD = 10000;
void add(int64_t& a, int64_t b){
  a = (a+b) % MOD;
}
void mul(int64_t& a, int64_t b){
  a = a*b % MOD;
}

int main() {
  int N, K;
  cin >> N >> K;

  // F[i] : i日目のパスタが指定されているならその番号、指定されていないなら-1
  vector<int> F(N, -1);
  while(K--){
    int a, b;
    cin >> a >> b;
    // 0-indexed
    F[a-1] = b-1;
  }
  // dp[i][a][b]=  i−1 日目までのパスタの選び方で、i−2 日目のパスタが a、i−1 日目までのパスタが b であるようなものの総数
  int64_t dp[101][3][3] = {0};
  dp[0][0][0] = 1;

  for(int i=0; i<N; i++) for(int a=0; a<3; a++) for(int b=0; b<3; b++){
    // cs : i日目のパスタの候補
    vector<int> cs = {0, 1, 2};
    // その日のパスタが既に決まっている場合書き換え
    if(F[i] >= 0) cs = {F[i]};

    // 今日のパスタを全探索
    for(int c : cs){
      // 「3日連続同じ」なら抜ける、そうでなければ遷移
      if(i >= 2 && a==b && b==c) continue;
      // 一昨日はa, 昨日はb, 今日はcのパスタを食べる
      add(dp[i+1][b][c], dp[i][a][b]);
    }
  }

  int64_t ans = 0;
  // N日目に食べたパスタbと昨日食べたパスタaの組み合わせを全探索(9通り)して合計
  for(int a=0; a<3; a++) for(int b=0; b<3; b++) add(ans, dp[N][a][b]);
  cout << ans << endl;
}