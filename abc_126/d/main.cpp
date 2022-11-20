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

using vvpii = vector<vector<pair<int, int>>>;
int N;
int u[100007], v[100007], w[100007];

bool used[100007];
int colors[100007];
vvpii graph(100007, vector<pair<int, int>>());

int main(void) {
  cin >> N;
  debug(N);
  rep(i, N-1) {
    cin >> u[i] >> v[i] >> w[i];
    graph[u[i]].push_back({v[i], w[i]});
    graph[v[i]].push_back({u[i], w[i]});
  }

  queue<int> que;
  que.push(1);
  used[1] = true;
  colors[1] = 0;
  // 幅優先探索
  while (!que.empty()) {
    auto q = que.front();
    que.pop();

    fore(x, graph[q]) {
      // 訪問済みならcontinue
      if (used[x.first]) continue;
      if (x.second % 2 == 1) {
        colors[x.first] = !colors[q];
      } else {
        colors[x.first] = colors[q];
      }
      used[x.first] = true;
      que.push(x.first);
    }
  }

  for(int i = 1; i <= N;i++) {
    cout << colors[i] << endl;
  }
}



// DFSでも解けたぽい
// int N;
// vector<pair<int, int>> E[101010];
// //---------------------------------------------------------------------------------------------------
// int ans[101010];
// // cu: 現在の頂点, pa: 親頂点, col: 色
// void dfs(int cu, int pa = -1, int col = 0) {
//   // 色をセット
//   ans[cu] = col;
//   fore(p, E[cu]) {
//     if (p.first == pa) continue;

//     // 辺の長さが偶数なら色そのまま、異なれば色を変える(1-0 = 1, 1-1=0)
//     if (p.second % 2 == 0) dfs(p.first, cu, col);
//     else dfs(p.first, cu, 1 - col);
//   }
// }
// //---------------------------------------------------------------------------------------------------
// int main() {
//   cin >> N;
//   rep3(i, 0, N - 1) {
//     int a, b, c; cin >> a >> b >> c;
//     a--; b--;

//     E[a].push_back({ b,c });
//     E[b].push_back({ a,c });
//   }

//   dfs(0);

//   rep3(i, 0, N) printf("%d\n", ans[i]);
//   return 0;
// }