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

// 1と0を繰り返している、aが1,3,5..を取るとき(a+1)/2は1, 2, 3..を取る、2,4,6...を2で割った数列となる
long long oddsolve(long long a) { return (a+1)/2 % 2; }

long long solve(long long a) {
  // 奇数なら奇数について解いたものを返す
  if (a % 2 == 1) return oddsolve(a);
  // 偶数ならa+1までの和からa+1を引く(XORを取る)
  else return oddsolve(a+1) ^ (a+1);
}

int main() {
  // XOR の世界では「足し算」も「引き算」も一緒
  // B以下についての答えからA-1以下の値についての答えを引く
  // Q = 0  ^ 1 ^ 2 ^ … ^ (A−1) ^ A ^ (A+1) ^ … ^ B
  // P = 0 ^ 1 ^ 2 ^ … ^ (A−1)
  // Q ^ P = A ^ (A+1) ^ … ^ B
  // 1+2 = 1 ^ 10 = 11(3)
  // 3-2 = 11 ^ 10 = 1(1)
  // 3-1 = 11 ^ 1 = 10(2)
  ll A, B;
  cin >> A >> B;
  // BまでのXOR和からA-1までのXOR和を引いている
  cout << (solve(B) ^ solve(A-1)) << endl;
  return 0;
}