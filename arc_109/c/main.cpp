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

int main() {
  char win[222][222];
  // 勝つ組み合わせを記録
  win['R']['R'] = win['R']['S'] = win['S']['R'] = 'R';
  win['S']['S'] = win['S']['P'] = win['P']['S'] = 'S';
  win['P']['P'] = win['P']['R'] = win['R']['P'] = 'P';

  int n, m;
  string s;
  cin >> n >> m >> s;
  // 各選手が最初の試合を終えた直後に、勝ち残ってる選手のうち i 番目に小さい整数の参加者について考える
  // 対戦の方法から、これは番号 2i の参加者と番号 2i+1 の参加者が試合をしたときの勝者である
  // iは0からスタートするものとする
  // よって、各選手が最初の試合を終えた直後に勝ち残ってる選手の
  // 得意な手を順番に並べた文字列を考えると、i 番目の文字は s[2i]とs[2i+1]のうち負けない方の手
  // m回操作を行う
  // O(mn)で10000程度で済む
  // この状態は、参加者の得意な手が、以下で定義される文字列 t で表され、参加者の人数が 2^(k−1)
  // 人だった場合と同じ
  while (m--) {
    // sを2つ並べる、tが偶数の方がやりやすいため、つまり1人だけ余るということがないため
    const auto t = s + s;
    debug(t);
    // 文字数分操作を行う
    // 勝った人の得意な手でsを更新していく
    // この1~m回戦目まであり(2^mが1人になるにはm回戦行うことが必要)、その勝者は
    // ここで更新したsの繰り返しによって表現できる
    rep(i, n) {
      debug(win[t[i * 2]][t[i * 2 + 1]]);
      s[i] = win[t[i * 2]][t[i * 2 + 1]];
    }
  }
  // そしてm回戦が終わった時、0番目にある文字列が勝者の得意とする手になる
  cout << s[0] << endl;
  return 0;
}