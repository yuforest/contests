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

vector<ll>dx={1,-1,0,0,1,1,-1,-1};
vector<ll>dy={0,0,1,-1,1,-1,1,-1};

int main() {
  ll H, W;
  cin >> H >> W;
  string S[H];
  rep(i, H) cin >> S[i];
  vvc ans(H, vc(W, '.'));
  rep(i, H) {
    rep(j, W) {
      bool all = true;
      if (S[i][j] != '#') continue;
      rep(k, 8) {
        ll nx = i + dx[k];
        ll ny = j + dy[k];
        if (nx < 0 || nx > H-1) continue;
        if (ny < 0 || ny > W-1) continue;
        if (S[nx][ny] == '.') all = false;
      }
      if (all) ans[i][j] = '#';
    }
  }
  debug(ans);
  vvc check(H, vc(W, '.'));
  rep(i, H) {
    rep(j, W) {
      if (ans[i][j] != '#') continue;
      check[i][j] = '#';
      rep(k, 8) {
        ll nx = i + dx[k];
        ll ny = j + dy[k];
        if (nx < 0 || nx > H-1) continue;
        if (ny < 0 || ny > W-1) continue;
        check[nx][ny] = '#';
      }
    }
  }
  debug(check);
  rep(i, H) {
    rep(j, W) {
      if (check[i][j] != S[i][j]) {
        cout << "impossible" << endl;
        return 0;
      }
    }
  }
  cout << "possible" << endl;
  rep(i, H) {
    rep(j, W) {
      cout << ans[i][j];
    }
    cout << endl;
  }

  
  return 0;
}