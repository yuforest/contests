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

// ハッシュ値の計算
int hash_val(const string &s){
  int ret=0;
  for(int i=0;i<s.size();i++){
    ret+=s[i]-'a'+1;
  }
  return ret;
}

bool match[27*100];
string ss[27*100];

int h=0;
string t;

// 全てのとりうるハッシュ値で入力された文字と異なるものをメモ化再帰で探索
void dfs(string s){
  // 今の文字列のハッシュ値を計算
  int h=hash_val(s);
  // 20文字より大きければ枝刈り
  if(s.size() > 20)return;
  // 既にマッチした文字列が過去に存在すれば枝刈り
  // 同じようなハッシュ値になるものは過去に既に探索している
  if(match[h])return;
  // 入力された文字列と現在の文字列が異なる場合
  // 例えばaのハッシュ値は1だが、他にハッシュ値が1となる文字列はないので
  // この条件分岐内を通らない、よってこの答えはない
  if(t != s){
    // 答えとなる文字列を保存
    ss[h]=s;

    debug(h);
    // 見つかったフラグを立てる
    match[h]=true;
  }
  // 大きな方から再帰的に探索していく、そうすることで探索回数を少なくすることができる
  // 少ない文字数で大きなハッシュ値を実現できるため
  for(int i=25;i>=0;i--){
    dfs(s+(char)(i+'a'));
  }
  return;
}
int main() {
  string s;
  cin>>s;
  t=s;
  dfs("");
  string ret=ss[hash_val(s)];
  if(ret=="") ret="NO";
  cout<<ret<<endl;
  return 0;
}