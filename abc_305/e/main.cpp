// 標準ライブラリを全て読み込む
// 本書では細かく書きませんが、下記リンクが参考になります
// https://atcoder.jp/contests/apg4b/tasks/APG4b_af
#include <bits/stdc++.h>
// stdのstd::cinのような書き方ではなくcinと書けば良くなる
using namespace std;

// デバッグ用マクロ
// 本書では細かく書きませんが、下記リンクが参考になります
// https://naskya.net/post/0002/
#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

// データ構造の省略
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
// using pii = pair<int, int>;

// modの計算
long long mod1 = 1000000007;
long long mod2 = 998244353;

// 隣接グラフ(1 << 18は2^18で262144となる)
vector<ll> G[1 << 18];
// vector<ll> rG[1 << 18];

// ACL(AtCoder Library)、普段はコメントアウトしてある
#include <atcoder/all>
using namespace atcoder;

// repマクロ
// 0からn-1まで
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// aからb−1まで
#define rep3(i,a,b) for(int i=a;i<b;i++)
// n-1から0まで
#define per(i, n) for (int i = int(n) - 1; i >= int(0); i--)
// b-1からaまで
#define per3(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
// 範囲for文の省略
#define fore(i,a) for(auto &i:a)
// sort(A.begin(), A.end())をsort(all(A))のように書けます
#define all(x) (x).begin(), (x).end()

// 最大値と最小値の更新
// 返り値は更新した場合はtrue、そうでなければfalse
template <typename T>
inline bool chmax(T &a, T b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T>
inline bool chmin(T &a, T b) {
  return ((a > b) ? (a = b, true) : (false));
}

int main() {
  int N, M, K;
  cin >> N >> M >> K;
  vector<vector<int>> g(N);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b, --a, --b;
    g[a].push_back(b), g[b].push_back(a);
  }
  vector<int> p(K), h(K);
  for (int i = 0; i < K; i++) cin >> p[i] >> h[i], p[i]--;
  // 頂点iにたどり着いた警備員の体力の最大値
  vector<int> d(N, -1);
  // 体力と頂点のペアを管理する優先度付きキュー
  priority_queue<pair<int, int>> Q;
  auto add = [&](int v, int x) {
    // 今の頂点の体力よりも大きい場合は更新する
    if (d[v] < x) Q.emplace(d[v] = x, v);
  };
  for (int i = 0; i < K; i++) add(p[i], h[i]);
  // 空になるまで繰り返す
  while (Q.size()) {
    auto [x, v] = Q.top();
    Q.pop();
    // 今の体力がd[v]よりも小さい場合は無視する
    if (d[v] != x) continue;
    // 体力を減らして次の頂点を訪問
    for (auto& u : g[v]) add(u, d[v] - 1);
  }
  vector<int> ans;
  for (int i = 0; i < N; i++)
    if (d[i] >= 0) ans.push_back(i + 1);
  cout << ans.size() << "\n";
  for (int i = 0; i < (int)ans.size(); i++)
    cout << ans[i] << " \n"[i + 1 == (int)ans.size()];
}