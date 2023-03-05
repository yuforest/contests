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

string S1, S2, S3;
#define NOANS "UNSOLVABLE"
//---------------------------------------------------------------------------------------------------
vector<char> chars;
// 文字配列
char used[10];

bool check() {
  map<char, char> mapping;
  // 文字から数字への変換を行う
  rep(i, 10) if (used[i] != 0) mapping[used[i]] = char('0' + i);

  // 文字を数字に変換した文字列を保存する変数
  string SS1, SS2, SS3;
  fore(c, S1) SS1 += mapping[c];
  fore(c, S2) SS2 += mapping[c];
  fore(c, S3) SS3 += mapping[c];

  // 整数に変換してから再度文字列にした時に同じになるか
  // つまり最初に余分な0がついていないか
  // 全探索すると最初に0がつく場合も含まれてしまうのでそれを弾くためのチェック
  if (to_string(stoll(SS1)) != SS1) return false;
  if (to_string(stoll(SS2)) != SS2) return false;
  if (to_string(stoll(SS3)) != SS3) return false;
  // 式があっているか
  if (stoll(SS1) + stoll(SS2) != stoll(SS3)) return false;
  // 全て正の整数であることを確認
  if (stoll(SS1) == 0) return false;
  if (stoll(SS2) == 0) return false;
  if (stoll(SS3) == 0) return false;

  cout << SS1 << endl;
  cout << SS2 << endl;
  cout << SS3 << endl;
  // 引っ掛からなければtrue
  return true;
}

// cu番目の文字まで確定させている状態で入ってくる
bool dfs(int cu) {
  // 出現する全ての文字の割り当てが完了したら成り立つかチェックする
  if (cu == chars.size()) return check();

  // iが使用済みでなければ
  rep(i, 10) if (used[i] == 0) {
    // 文字の割り当て
    used[i] = chars[cu];
    // 1増やしてdfsを行う, trueになるものがあればtrueを返す
    if (dfs(cu + 1)) return true;
    // 未使用に戻す
    used[i] = 0;
  }

  // 全部試してもダメならfalse
  return false;
}
//---------------------------------------------------------------------------------------------------
int main() {
  cin >> S1 >> S2 >> S3;

  // 登場する文字を全て一つにまとめ重複削除
  fore(c, S1) chars.push_back(c);
  fore(c, S2) chars.push_back(c);
  fore(c, S3) chars.push_back(c);
  sort(all(chars));
  chars.erase(unique(all(chars)), chars.end());

  // この時点で10文字以上使われてたら明らかに成り立たない
  if (10 < chars.size()) {
    cout << NOANS << endl;
    return 0;
  }

  // 深さ優先探索、実現可能かをチェック
  bool res = dfs(0);
  // だめならその旨を出力
  if (res == false) cout << NOANS << endl;
}