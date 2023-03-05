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


vector<int> number(const string &s) {
  vector<int> res(26);
  // 数字の配列に変換する
  for (char c : s) res[c-'A']++;
  return res;
}

// S1から取り出す文字数が少なすぎると、S2から取り出す文字数に関わらず、S3を構成するのに足りない
// S1から取り出す文字数が多すぎると、S2から取り出す文字数に関わらず、S3を構成するのに余る
// 取り出し方をアルファベットごとに独立して考えることができる
// 上限と下限の間にあるかどうかで判定
// 例えば下記のような場合には最低でもS1から4つ取る必要があり、3つより大きい
// AAAAAB
// CCCCCB
// AAABCB
string solve() {
  string s1, s2, s3;
  cin >> s1 >> s2 >> s3;
  int N = s1.size() / 2;
  vector<int> num1 = number(s1), num2 = number(s2), num3 = number(s3);
  // S1から特定の文字をできるだけ少なく、またはできるだけ多く取り出したときに取り出す数の合計
  int minimum = 0, maximum = 0;
  // 文字ごとに見ていく
  rep(i,26) {
    // 足しても構築できなければ実現不可能
    if (num1[i] + num2[i] < num3[i]) return "NO";
    // できるだけ少なくS1から取り出した時(num3[i] - num2[i]個はS1から取り出す必要がある)
    // 例えばどちらにもこの文字がない場合でもminimumにはnum3[i]が足される
    minimum += max(0, num3[i] - num2[i]);
    debug(max(0, num3[i] - num2[i]));
    // できるだけ多くS1から取り出した時(num1[i]とnum3[i]の小さい方だけ取り出せる)
    // S1現在の文字全てを使っても足りない場合にはnum1[i]だけ足される
    maximum += min(num1[i], num3[i]);
    debug(min(num1[i], num3[i]));
  }
  debug(minimum);
  debug(maximum);
  // S1から取り出す文字数はminimumとmaximumの範囲の全てを取ることができる
  // Nがminimumとmaximumの範囲に収まっていればよい
  if (minimum <= N && N <= maximum) return "YES";
  return "NO";
}

int main() {
  cout << solve() << endl;
  return 0;
}
