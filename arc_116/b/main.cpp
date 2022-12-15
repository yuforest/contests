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

long long MOD = 998244353;
int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; i++){
    cin >> A[i];
  }
  // ソート
  sort(A.begin(), A.end());
  long long ans = 0, sum = 0;
  ans = 0;
  // 最後の値
  sum = A[N - 1];
  // ここでは異なる要素が最大最小である時を想定する
  // A = (1, 2, 3, 4, 5) のケース
  // 合計されるのは、1 ~ それぞれの最大値の間に挟まる数が
  // それぞれある場合、ない場合の 2 通りずつになるので、
  // 最大値 1: 1 * 1 -> 1回 （数字が 1 しか残っていないケース）
  // 最大値 2: 1 * 2 -> 1回 （数字が 1, 2 しか残っていないケース）
  // 最大値 3: 1 * 3 -> 2回 （1 ～ 3 の間の 2 が 残る／残らない ケース）
  // 最大値 4: 1 * 4 -> 2^2回 (1 ～ 4 の間の 2, 3 がそれぞれ 残る／残らない)
  // 最大値 5: 1 * 5 -> 2^3回 （1 ～ 5 の間の 2, 3, 4 が以下略）
  // 同様に最小値が 2 の場合を考えると、
  // 最大値 2: 2 * 2 - 1回
  // 最大値 3: 2 * 3 - 1回
  // 最大値 4: 2 * 4 - 2回
  // 最大値 5: 2 * 5 - 2^2回
  // 数字が一つしか残らない場合を別に扱うと、
  // 最小値 1 の場合：
  // (1 * 1) + 1 * (2 * 1 + 3 * 2 + 4 * 2^2 + 5 * 2^3)
  // 最小値 2 の場合：
  // (2 * 2) + 2 * (3 * 1 + 4 * 2 + 5 * 2^2)
  // 以下同様に、
  // (3 * 3) + 3 * (4 * 1 + 5 * 2)
  // (4 * 4) + 4 * (5 * 1)
  // (5 * 5) + 5 * (0)

  // ここで一番右のカッコ内に注目すると、
  // 最小値が減るに従って、2 倍して前の最大値を足した値になっている
  // これは O(1) で求められるので、全体でも O(N) でいけそう。
  for (int i = N - 2; i >= 0; i--){
    // 現在の合計にA[i]を掛ける
    ans += A[i] * sum % MOD;
    ans %= MOD;
    // 合計の2倍にA[i]を足す
    // 分配法則により(A+B)*2=2A+2Bのような感じで問題なく計算できる
    sum = sum * 2 + A[i];
    sum %= MOD;
  }
  // 部分列で自分のみを選んだ時の値
  for (int i = 0; i < N; i++){
    ans += A[i] * A[i] % MOD;
    ans %= MOD;
  }
  cout << ans << endl;

  return 0;
}