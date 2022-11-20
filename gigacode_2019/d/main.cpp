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

int main() {
  ll H, W, K, V;
  cin >> H >> W >> K >> V;
  vvl A(H+1, vl(W+1, 0));
  rep3(i, 1, H+1) {
    rep3(j, 1, W+1) {
      cin >> A[i][j];
      A[i][j] += A[i][j-1];
    }
  }
  rep3(i, 1, W+1) {
    rep3(j, 1, H+1) {
      A[j][i] += A[j-1][i];
    }
  }
  debug(A);
  ll ans = 0;
  rep3(h1, 1, H+1) {
    rep3(w1, 1, W+1) {
      rep3(h2, h1, H+1) {
        rep3(w2, w1, W+1) {
          ll area = (h2 - h1 + 1) * (w2 - w1 + 1);
          // 家と土地の合計
          ll cost = (area * K) + A[h2][w2] - A[h2][w1-1] - A[h1-1][w2] + A[h1-1][w1-1];
          if (cost <= V) {
            debug(area);
            chmax(ans, area);
          }
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}