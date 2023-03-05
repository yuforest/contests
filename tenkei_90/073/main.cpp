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

long long N, A[1 << 18], B[1 << 18];
char C[1 << 18];

// long long mod = 1000000007;
// 2つ目のインデックスは0: 'a'のみ, 1: 'b'のみ, 2: 'a'と'b'の両方
// 頂点posの部分木を考えた時に何通りあるか
long long dp[1 << 18][3];
// vector<int> G[1 << 18];

// 木DPを行う
void dfs(int pos, int pre) {
  long long val1 = 1, val2 = 1;
  // 隣接頂点の探索
  for (int i : G[pos]) {
    // 親は除く
    if (i == pre) continue;
    dfs(i, pos);
    // 今の頂点が'a'の場合
    if (C[pos] == 'a') {
      // dp[pos][0]の値を計算
      // posの部分木はaしか含まないようにする時に
      // 1. 子の連結成分が'a'の状態かつ、連結している
      // 2. 子の連結成分が'ab'の状態かつ、連結していない
      val1 *= (dp[i][0] + dp[i][2]);
      // dp[pos][2]の値を計算
      // 1. 子の連結成分が'a'の状態かつ、連結している
      // 2. 子の連結成分が'b'の状態かつ、連結している
      // 3. 子の連結成分が'ab'の状態かつ、連結している
      // 4. 子の連結成分が'ab'の状態かつ、連結していない
      val2 *= (dp[i][0] + dp[i][1] + 2LL * dp[i][2]);
    }
    if (C[pos] == 'b') {
      // dp[pos][1]の値を計算
      val1 *= (dp[i][1] + dp[i][2]);
      // dp[pos][2]の値を計算
      val2 *= (dp[i][0] + dp[i][1] + 2LL * dp[i][2]);
    }
    val1 %= mod;
    val2 %= mod;
  }

  // 今の頂点の文字列の個数を更新
  // 状態2については、辺を削除しない場合はなんでもありだが
  // 削除する場合は、dp[bi][2]の状態から遷移する必要がある
  // つまり子にC[pos]でない文字が含まれていない通り数を引く必要がある(val1)
  if (C[pos] == 'a') {
    dp[pos][0] = val1;
    dp[pos][2] = (val2 - val1 + mod) % mod;
  }
  if (C[pos] == 'b') {
    dp[pos][1] = val1;
    dp[pos][2] = (val2 - val1 + mod) % mod;
  }
}

int main() {
  // Step #1. Input
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> C[i];
  for (int i = 1; i <= N - 1; i++) {
    cin >> A[i] >> B[i];
    G[A[i]].push_back(B[i]);
    G[B[i]].push_back(A[i]);
  }

  // Step #2. DFS
  dfs(1, -1);
  // 頂点1の部分木における'a'と'b'の両方の文字列の個数を出力
  cout << dp[1][2] << endl;
  return 0;
}