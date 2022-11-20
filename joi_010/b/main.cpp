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

int ans[2010];

int main() {
  ll D, N, M;
  cin >> D >> N >> M;
  vl shops(N);
  vl homes(M);
  shops[0] = 0;
  rep3(i, 1, N) {
    cin >> shops[i];
  }
  sort(shops.begin(), shops.end());
  rep(i, M) {
    cin >> homes[i];
  }
  debug(shops);
  debug(homes);
  ll ans = 0;
  rep(i, M) {
    auto pos = lower_bound(shops.begin(), shops.end(), homes[i]);
    ll dist1;
    ll dist2;
    // 最後の店舗より先にある
    if (pos == shops.end()) {
      dist1 = abs(homes[i] - D);
      dist2 = abs(homes[i] - shops[N-1]);
    } else {
      int index = pos - shops.begin();
      dist1 = abs(homes[i] - shops[index]);
      dist2 = abs(homes[i] - shops[index-1]);
    }
    debug(dist1);
    debug(dist2);
    ans += min(dist1, dist2);
  }
  cout << ans << endl;
  return 0;
}