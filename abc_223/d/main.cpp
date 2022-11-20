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
  int N, M;
  cin >> N >> M;
  vector<int> indeg(N);
  vector<vector<int>> out(N);
  for (int i = 0; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    a -= 1;
    b -= 1;
    // 入次数 (indegree)を記録する配列
    // bに対して入ってきた辺の数を数える
    indeg[b] += 1;
    // 辺を追加
    out[a].push_back(b);
  }
  // 昇順の優先度付きキュー
  priority_queue<int, vector<int>, greater<int>> heap;
  for (int i = 0; i < N; ++i) {
    // 入次数が0のものを追加していく
    // つまりこのとき先にくる頂点が指定されていない頂点を追加している
    // 1->2かつ2->1など互いに依存関係がある場合、
    // どちらも入次数が1になってここで追加されない
    // 3点以上の頂点で閉路がある場合も同様
    if (indeg[i] == 0) {
      heap.push(i);
    }
  }
  vector<int> ans;
  // 容量の確保
  ans.reserve(N);
  // 空になるまで処理を行う
  // 探索できるものから探索していくイメージ
  // 小さい順に探索して、頂点の順番の依存関係が消えた時点で
  // 優先度付きキューに追加していく
  // 追加されたものも含めて小さい順に再度探索していく
  while (!heap.empty()) {
    debug(heap);
    int i = heap.top();
    heap.pop();
    // 答えに追加
    ans.push_back(i);
    // 入次数が0の頂点を起点とする頂点を探索
    for (int j : out[i]) {
      // 繋がっている頂点の入次数を減らす
      indeg[j] -= 1;
      // この時点で入次数が0であれば優先度付きキューに追加
      if (indeg[j] == 0) {
        heap.push(j);
      }
    }
  }
  // 全ての頂点が含まれていなければ、要求された並べ方をすることは不可能である
  if (size(ans) != N) {
    cout << -1 << '\n';
  } else {
    for (int i = 0; i < N; ++i) {
      cout << ans[i] + 1 << (i + 1 == N ? '\n' : ' ');
    }
  }
}