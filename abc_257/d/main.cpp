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

ll N;
ll x[201], y[201], P[201];

bool canMove(ll S, int from, int to) {
  return P[from] * S >= abs(x[from] - x[to]) + abs(y[from] - y[to]);
}

// 適切に始点を定めることで、今のトレーニング回数で全ての頂点を訪問できるかという判定問題
// O(N^3)
bool check(ll S) {
  // 全ての頂点を探索
  rep(start, N) {
    set<int> visited;
    queue<int> que;

    visited.insert(start);
    que.push(start);
    // 幅優先探索
    while (!que.empty()) {
      int cur = que.front();
      que.pop();

      // 現在以外の全ての頂点を探索
      rep(to, N) if (to != cur) {
        // 移動できて、未訪問なら頂点に訪問して探索候補に加える
        if (canMove(S, cur, to) && !visited.count(to)) {
          visited.insert(to);
          que.push(to);
        }
      }
    }
    // 終わった時に全ての頂点を訪問できていればOK
    if (visited.size() == N) return true;
  }

  return false;
}

int main() {
  cin >> N;
  rep(i, N) cin >> x[i] >> y[i] >> P[i];

  // ngを左側、okを右側として見ていく
  // okの初期値は4*10^9以上にしておく必要がある
  ll ng = -1, ok = 4000000001LL;
  while (ng + 1 != ok) {
    ll md = (ng + ok) / 2;
    if (check(md)) ok = md;
    else ng = md;
  }
  cout << ok << endl;
}