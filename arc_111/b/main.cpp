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


using mint = atcoder::modint998244353;
int main() {
  ll H, W;
  cin >> H >> W;
  string S[H];
  rep(i, H) cin >> S[i];
  // ある地点まで同じ経路でそこから(i+1,j)->(i+1, j+1)
  // の遷移と(i, j+1)->(i+1, j+1)の遷移で色が揃わなければいけない
  // i+j が同じようなマス (i,j) は全て同じ色である必要がある
  mint ans = 1;
  // このやり方によって斜めに同じ距離のものを探索することができる
  // mは同じ距離の座標が出てくる回数になっている
  for( int m = 1; m < H + W; m++ ) {
    int r = 0, b = 0, n = 0;
    debug(m);
    for( int i = 0; i < m; i++ ) {
      // 座標を合計してm-1なのでjはm-1-iで求められる
      int j = m - 1 - i;
      debug(i);
      debug(j);
      // 範囲外ならcontinue
      if( i >= H || j >= W ) continue;
      if( S[i][j] == 'R' ) r++;
      else if( S[i][j] == 'B' ) b++;
      else n++;
    }
    // どちらも存在すると矛盾してしまうので0
    if( r && b ) ans *= 0;
    // 全てが任意に選べる場合に通りあるので2を掛ける
    else if( r == 0 && b == 0 ) ans *= 2;
  }
  cout << ans.val() << endl;

  return 0;
}