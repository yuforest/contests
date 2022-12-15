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
  ll N;
  cin >> N;
  ll a, b;
  cin >> a >> b;
  a--;b--;
  ll M;
  cin >> M;
  rep(i, M) {
    ll x, y;
    cin >> x >> y;
    x--;
    y--;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  // その町までの距離と訪問回数を入れる
  vpll dist(N, {-1, 0});
  dist[a].first = 0;
  dist[a].second = 1;
  queue<ll> que;
  que.push(a);
  while(!que.empty()) {
    ll val = que.front();
    que.pop();
    for(auto x: G[val]) {
      if (dist[x].first != -1) {
        // 既に訪問済みの場合、最短経路でなければcontinue
        if (dist[x].first != dist[val].first + 1) continue;
        // 現在いるマスの経路数を足してmodをとる
        dist[x].second += dist[val].second;
        dist[x].second %= mod;
      } else {
        // 訪問済みでなければ最短距離を記録して現在いるマスの経路数を足してmodをとる
        dist[x].first = dist[val].first + 1;
        dist[x].second += dist[val].second;
        dist[x].second %= mod;
        // 後で探索するように追加
        que.push(x);
      }
    }
  }
  cout << dist[b].second << endl;
  return 0;
}