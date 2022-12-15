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

int N;
string S;
vector<string> T;
vector<int> memo;
// メモ化再帰(動的計画法)
// i文字目までのフレーズの並べ方の通り数を計算する
int f(int i){
  // iが0より小さくなってしまった場合は実現不可能なので0通り
  if(i < 0)return 0;
  // 先頭から0文字までの並べ方の通り数は1通り
  if(i == 0)return 1;
  // 既に結果が保存されていたらそれを返す
  if(memo[i] != -1)return memo[i];
  // 合計の通り数
  int ret = 0;
  // フレーズの配列の中身を見ていく
  for(const string& t : T) {
    // i文字目までの最後のフレーズの長さ分の文字列がtと一致していたらそれ以前に関して
    // 再帰関数を呼び出して通り数を求める
    // つまり文字列を最後から見ていって、通り数を求めていく
    if(i >= t.length() && S.compare(i - t.length(), t.length(), t) == 0) {
      ret = (ret + f(i - t.length())) % 1000000007;
    }
  }
  // メモに保存して値を返す
  return memo[i] = ret;
}

int main(){
  cin >> N;
  cin >> S;
  T.resize(N);
  for(int i=0; i<N; ++i)cin >> T[i];

  // -1で初期化
  memo = vector<int>(S.length() + 1, -1);
  cout << f(S.length()) << endl;
  debug(memo);
  return 0;
}