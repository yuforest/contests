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

long long mod = 1000000007;
// vector<ll> G[1 << 18];

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



vvvi sum(301, vvi(301, vi(301, 0)));
int main() {
  ll H, W, N, h, w;
  cin >> H >> W >> N >> h >> w;
  // 300*300 = 90000 = 9 * 10^4
  // N^3がギリ通るか
  vvl A(H+1, vl(W+1));
  map<ll, ll> mp;
  rep3(i, 1, H+1) {
    rep3(j, 1, W+1) {
      cin >> A[i][j];
      mp[A[i][j]]++;
    }
  }
  debug(A);
  // 二次元累積和的に計算する
  rep3(i, 1, H+1) {
    rep3(j, 1, W+1) {
      ll current = A[i][j];
      sum[i][j][current]++;
      rep3(k, 1, N+1) {
        sum[i][j][k] += sum[i][j-1][k];
        sum[i][j][k] += sum[i-1][j][k];
        sum[i][j][k] -= sum[i-1][j-1][k];
      }
    }
  }
  debug(mp);
  rep3(i, 1, H-h+2) {
    rep3(j, 1, W-w+2) {
      ll val = N;
      // debug(i);
      // debug(j);
      rep3(k, 1, N+1) {
        ll tmp = sum[i+h-1][j+w-1][k] - sum[i-1][j+w-1][k] - sum[i+h-1][j-1][k] + sum[i-1][j-1][k];
        // ll tmp = sum[i+h-1][j+w-1][k] - sum[i][j][k];
        // cout << k << endl;
        // cout << i << " " << j << " " << i+h-1 << " " << j+w-1 << endl;
        // debug(sum[i+h-1][j+w-1][k]);
        // debug(sum[i-1][j-1][k]);
        // debug(mp[k]);
        // debug(tmp);
        if (mp[k] == tmp) {
          val--;
        }
      }
      if (j > 1) cout << " ";
      cout << val;
    }
    cout << endl;
  }
  debug(sum[2][2][2]);
}