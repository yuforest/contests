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

int main() {
  string S, T;
  cin >> S >> T;
  map<char, int> s_cnt;
  map<char, int> t_cnt;
  ll n = S.size();
  ll m = T.size();
  rep(i, n) s_cnt[S[i]]++;
  rep(i, m) t_cnt[T[i]]++;

  for(auto x: t_cnt) {
    debug(x.first);
    if (!s_cnt[x.first]) {
      cout << -1 << endl;
      return 0;
    }
  }
  map<char, vector<int>> positions;
  rep(i, n) {
    positions[S[i]].push_back(i);
  }
  debug(positions);
  ll ans = 0;
  ll cur = 0;
  rep(i, m) {
    auto array = positions[T[i]];
    auto pos = lower_bound(array.begin(), array.end(), cur);
    debug(cur);
    if (pos == array.end()) {
      pos = lower_bound(array.begin(), array.end(), 0);
      int index = pos - array.begin();
      ans += (n-cur) + array[index] + 1;
      debug(n-cur);
      debug(array[index] + 1);
      cur = array[index] + 1;
    } else {
      int index = pos - array.begin();
      ans += array[index] - cur + 1;
      cur = array[index] + 1;
    }
    debug(ans);
  }
  cout << ans << endl;
}