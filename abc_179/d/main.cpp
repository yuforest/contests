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


template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;
#define pb push_back
#define eb emplace_back
using mint = atcoder::modint998244353;


int main() {
  int N, K;
  cin >> N >> K;
  V<pii> rng;

  rep(i, K) {
    int l, r;
    cin >> l >> r;
    // rは+1することで[l,r)の半開区間にしておく
    r++;
    rng.eb(l, r);
  }

  V<mint> dp(N);
  // いもす方的な考え方で0にだけ値が入っているので1番目で引いておく必要がある
  dp[0] = 1;
  dp[1] = -1;

  // 累積和的な考え方をする
  // いもす方をdpに適用するイメージ
  rep(i, N) {
    // iが1以上の時は前の値を今の値に持ってくる
    // これがいもす法の肝、累積和を作るためのきも
    if (i > 0) dp[i] += dp[i - 1];
    // 区間の数はK個しかない
    rep(j, K) {
      int l, r;
      // lとrにrng[j]の中身を展開する
      tie(l, r) = rng[j];
      // Nを超えない限り区間の左側に今の値を足す
      if (i + l < N) dp[i + l] += dp[i];
      // Nを超えない限り区間の右側から今の値を引く
      if (i + r < N) dp[i + r] -= dp[i];
    }
  }
  // 0からN-1まで
  cout << dp[N - 1].val() << endl;

  return 0;
}