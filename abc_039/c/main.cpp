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

int ans[2010];
int N, M;

int main() {
  string S;
  cin >> S;
  vi mi_or_si;
  rep(i, 19) {
    if (S[i] == 'W' && S[i+1] == 'W') {
      mi_or_si.push_back(i);
    }
  }
  bool is_mi = false;
  bool is_si = true;
  if (mi_or_si[1] - mi_or_si[0] == 7) {
    is_si = false;
    is_mi = true;
  }
  debug(mi_or_si);
  debug(is_mi);
  debug(is_si);
  int count = mi_or_si[0];
  string ans;
  if (is_mi) {
    ans = "Mi";
  } else {
    ans = "Si";
  }
  debug(count);
  while(count > 0) {
    debug(ans);
    if (ans == "Mi") {
      count -= 2;
      ans = "Re";
    } else if (ans == "Re") {
      count -= 2;
      ans = "Do";
    } else if (ans == "Do") {
      count -= 1;
      ans = "Si";
    } else if (ans == "Si") {
      count -= 2;
      ans = "La";
    } else if (ans == "La") {
      count -= 2;
      ans = "So";
    } else if (ans == "So") {
      count -= 2;
      ans = "Fa";
    } else if (ans == "Fa") {
      count -= 1;
      ans = "Mi";
    }
  }
  cout << ans << endl;
  return 0;
}