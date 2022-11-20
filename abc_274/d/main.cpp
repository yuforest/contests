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

// 偶数index
bool dp1[1001][20001];
// 奇数index
bool dp2[1001][20001];
int main(void) {
  int N, x, y;
  cin >> N >> x >> y;
  vi A1;
  vi A2;
  rep(i, N) {
    int val;
    cin >> val;
    if (i%2 ==0) A1.push_back(val);
    else A2.push_back(val);
  }
  // 初期化
  dp1[0][10000] = true;
  dp1[1][10000+A1[0]] = true;
  dp2[0][10000] = true;
  // dp1
  rep3(i, 1, A1.size()) {
    rep(j, 20001) {
      if (dp1[i][j] == true) {
        dp1[i+1][j+A1[i]] = true;
        dp1[i+1][j-A1[i]] = true;
      }
    }
  }
  // dp2
  rep(i, A2.size()) {
    rep(j, 20001) {
      if (dp2[i][j] == true) {
        dp2[i+1][j+A2[i]] = true;
        dp2[i+1][j-A2[i]] = true;
      }
    }
  }
  rep(i, 20001) {
    if (dp1[A1.size()][i]) debug(i);
  }
  rep(i, 20001) {
    if (dp2[A2.size()][i]) debug(i);
  }
  if (dp1[A1.size()][x+10000] && dp2[A2.size()][y+10000]) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}