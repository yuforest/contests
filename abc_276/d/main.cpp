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

vector<pair<long long, long long> > prime_factorize(long long N) {
  vector<pair<long long, long long> > res;
  for (long long a = 2; a * a <= N; ++a) {
    if (N % a != 0) continue;
    long long ex = 0; // 指数

    // 割れる限り割り続ける
    while (N % a == 0) {
      ++ex;
      N /= a;
    }

    // その結果を push
    res.push_back({a, ex});
  }

  // 最後に残った数について
  if (N != 1) res.push_back({N, 1});
  return res;
}

int main() {
  ll N;
  cin >> N;
  ll a[N];
  rep(i, N) cin >> a[i];
  bool same = true;
  rep3(i, 1, N) {
    if (a[i-1] != a[i]) same = false;
  }
  if (same) {
    cout << 0 << endl;
    return 0;
  }
  ll common = 0;
  rep(i, N) {
    common = gcd(common, a[i]);
  }
  auto common_factor = prime_factorize(common);
  bool ok = true;
  ll ans = 0;
  rep(i, N) {
    auto val = prime_factorize(a[i]);
    rep(j, val.size()) {
      if (val[j].first != 2 && val[j].first != 3) {
        bool tmp = false;
        rep(k, common_factor.size()) {
          if (val[j].first == common_factor[k].first && val[j].second == common_factor[k].second) {
            tmp = true;
          }
        }
        if(!tmp) ok = false;
      } else {
        ans += val[j].second;
      }
    }
    debug(val);
  }

  rep(i, common_factor.size()) {
    if (common_factor[i].first == 2 || common_factor[i].first == 3) {
      ans -= common_factor[i].second * N;
    }
  }

  debug(common);
  if (!ok) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }

}