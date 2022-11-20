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

int main(void)
{
  ll N, M, Q;
  cin >> N >> M >> Q;
  vl W(N), V(N);
  rep(i, N) cin >> W[i] >> V[i];
  vl v(N);
  iota(v.begin(), v.end(), 0);
  // 価値が大きい順にソート
  sort(v.begin(), v.end(), [&](int i, int j) {
    return V[i] > V[j];
  });
  vl X(M);
  rep(i, M) cin >> X[i];
  rep(i, Q) {
    ll L, R;
    cin >> L >> R;
    L--;
    R--;
    auto X2 = X;
    ll ans = 0;
    rep(i, N) {
      ll index = v[i];
      ll contain = -1;
      ll current_size = 1e8;
      rep(j, M) {
        // 使えない箱の時はスキップ
        if (j >= L && j <= R) continue;
        // 荷物が箱に収まらない時はcontinue
        if (W[index] > X2[j]) continue;
        // 現在の荷物がより小さい箱に入るならその箱から埋めていく
        if (current_size > X2[j]) {
          chmin(current_size, X2[j]);
          contain = j;
        }
      }
      // 格納できる箱があるということ
      if (contain != -1) {
        ans += V[index];
        X2[contain] = 0;
      }
    }
    cout << ans << endl;
  }

}