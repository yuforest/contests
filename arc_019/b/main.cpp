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

int ans[2010];

int main() {
  string s;
  cin >> s;
  int n = s.size();
  int error = 0;
  // 文字列の半分まで探索することができる
  // 例えば5文字ならn-1-iは4-iとなり2文字目(0,1)まで行われる(真ん中はなんでも良い)
  // 4文字であれば3-iとなり、2文字目(0,1)まで行われる
  for(int i=0;i<n-1-i;i++){
    debug(i);
    // i文字目と反対からi文字目がでなければerrorをインクリメント
    if(s[i] != s[n-1-i]) error++;
  }
  // 全ての文字が同じ、つまり回文であれば
  if(error == 0){
    // 文字数が偶数なら、どの文字を変えても回文でなくすことができる
    // 奇数なら真ん中の文字以外を変えて回文でなくすことができる
    cout << 25*(n%2 == 0 ? n : n-1) << endl;
  } else if(error == 1){
    // 1文字だけ反対側の文字と同じでないものがあれば、
    // その2文字は反対側の文字が使えないので2通りを差し引く
    cout << 25*n-2 << endl;
  } else {
    // それ以外の場合はどの文字を変更しても回文でなくすことができる
    // なぜなら初期状態で揃っていない1組の文字をそろえたとしても他の組が
    // 異なるため回文にならないから
    cout << 25*n << endl;
  }
  return 0;
}