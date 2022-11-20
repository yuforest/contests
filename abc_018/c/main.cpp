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
int N, M;

int main() {
  int H1, W1;
  cin >> H1 >> W1;
  int A[H1][W1];
  rep(i, H1) {
    rep(j, W1) {
      cin >> A[i][j];
    }
  }

  int H2, W2;
  cin >> H2 >> W2;
  int B[H2][W2];
  rep(i, H2) {
    rep(j, W2) {
      cin >> B[i][j];
    }
  }

  string ans = "No";
  rep(h_bit, 1 << H1) {
    rep(w_bit, 1 << W1) {
      int b_h = 0;
      int b_w = 0;
      int a_h_size = 0;
      int a_w_size = 0;
      bool ok = true;
      rep(i, H1) {
        // この行は削除されている
        if (!(h_bit & (1 << i))) continue;
        a_h_size++;
        a_w_size = 0;
        rep(j, W1) {
          // この列は削除されている
          if (!(w_bit & (1 << j))) continue;
          a_w_size++;
          debug(A[i][j]);
          if (B[b_h][b_w] != A[i][j]) {
            ok = false;
          }
          if (b_w == W2-1) {
            b_w = 0;
            b_h++;
          } else {
            b_w++;
          }
        }
        debug("---");
      }
      debug(a_h_size);
      debug(a_w_size);
      if (a_h_size == H2 && a_w_size == W2 && ok) {
        ans = "Yes";
      }
      debug("\n");
    }
  }
  cout << ans << endl;
  return 0;
}