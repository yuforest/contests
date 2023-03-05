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



int L;
string S;


// 最長共通部分列
int lcs(string& AA,string& BB) {
  int x,y,ma=0;
  vvi dp(L+1, vi(L+1, 0));

  rep(x,AA.size()) rep(y,BB.size()) {
    // 今見ている文字が同じなら、どちらも次の文字に遷移した時と、現在の値に+1した値の
    // 大きい方で次の文字に遷移した時を更新する
    if(AA[x]==BB[y]) dp[x+1][y+1] = max(dp[x+1][y+1], dp[x][y]+1);
    // どちらも次の文字に遷移したときの最長の共通部分列の長さは
    // 今の位置からxを1進めた時か、yを1進めた時の値の大きい方となる
    dp[x+1][y+1]=max(dp[x+1][y+1],dp[x][y+1]);
    dp[x+1][y+1]=max(dp[x+1][y+1],dp[x+1][y]);
    // 最大値を更新
    ma=max(ma,dp[x+1][y+1]);
  }
  // debug(dp);
  return ma;
}

void solve() {

  cin>>L>>S;
  // 初期値として全ての文字を消した場合
  int mi = L;
  // 全ての分割位置を試す
  // 計算量はO(|S|^3) = 100^3 = 1000000程度
  for(int x=1;x<=L-1;x++) {
    string a=S.substr(0,x), b=S.substr(x);
    // 最長のLCSが分かれば、それ以外の文字を消せばよいだけ
    debug(lcs(a,b));
    mi = min(mi, L - 2*lcs(a,b));
  }
  cout << mi << endl;
}

int main() {
  solve();
}