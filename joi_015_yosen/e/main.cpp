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


typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
//---------------------------------------------------------------------------------------------------
// 昇順のpriority_queue
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
int N, M, K, S, P, Q;
vector<int> E[101010];
bool zombie[101010];
//---------------------------------------------------------------------------------------------------
bool danger[101010];
int dist[101010];
void bfs() {
  queue<int> que;

  rep3(i, 0, N) {
    if (zombie[i]) {
      dist[i] = 0;
      que.push(i);
    }
    else dist[i] = -1;
  }

  while (!que.empty()) {
    int cu = que.front(); que.pop();

    fore(to, E[cu]) if (dist[to] < 0) {
      dist[to] = dist[cu] + 1;
      que.push(to);
    }
  }
  // 全ての街を見て距離がS以下のものを危険とする
  rep3(i, 0, N) if (1 <= dist[i] && dist[i] <= S) danger[i] = true;
}
//---------------------------------------------------------------------------------------------------
bool vis[101010];
ll D[101010];
ll dijk() {
  rep3(i, 0, N) D[i] = infl;
  rep3(i, 0, N) vis[i] = false;

  min_priority_queue<pair<ll, int>> que;

  D[0] = 0;
  // コストと行き先
  que.push({ 0, 0 });

  while (!que.empty()) {
    auto q = que.top(); que.pop();

    ll cst = q.first;
    int cu = q.second;

    // Nに辿りついたらコストを返す
    if (cu == N - 1) {
      // Nの街では宿泊の必要がないので危険な街かどうかに応じて宿泊費を差し引く
      if (danger[cu]) return cst - Q;
      else return cst - P;
    }

    if (vis[cu]) continue;
    vis[cu] = 1;

    fore(to, E[cu]) {
      if (zombie[to]) continue;

      ll cst2 = cst;
      // 訪問先の町での宿泊費をプラスする
      if (danger[to]) cst2 += Q;
      else cst2 += P;
      // コスト更新
      if (chmin(D[to], cst2)) que.push({ D[to], to });
    }
  }

  return -1;
}

//---------------------------------------------------------------------------------------------------
int main() {
  cin >> N >> M >> K >> S >> P >> Q;
  rep3(i, 0, K) {
    int c; cin >> c; c--;
    zombie[c] = true;
  }
  rep3(i, 0, M) {
    int a, b; cin >> a >> b; a--; b--;
    E[a].push_back(b);
    E[b].push_back(a);
  }

  bfs();
  cout << dijk() << endl;
}