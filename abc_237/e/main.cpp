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

#define N 200010
#define INF (long long)2e+18
// 辺を通じてどの頂点からどの頂点へも移動可能である
// ポテンシャルは、最短経路探索を複数回行う際に、負辺を上手いこと解消する方法。
// 高橋君に対して (楽しさ)+(現在いる地点の標高) という量を考える
// 各広場について、その広場で移動を終えた時のその値の最大値が求まれば、
// その値からその広場の標高を差し引いた値を広場ごとに出して、最大を取れば答えが求まる
// よって、 (楽しさ)+(現在いる地点の標高) の −1 倍をコストとみなす
int main() {
  int n, m;
  long long h[N];
  vector<pair<int, long long> >e[N];
  // 降順のpriority_queue
  priority_queue<pair<long long, int> >pq;
  pair<long long, int> p;
  long long d[N];
  int k, x, y;
  long long ans;
  cin >> n >> m;
  for (int i = 0; i < n; i++)cin >> h[i];
  // グラフの構築
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    // 0-indexed
    x--;
    y--;
    // 双方向に辺を張る
    // ここでxの方が高い場合xからyにいく時はコスト0、yからxにいく時は2地点の標高差となる
    // ここでyの方が高い場合xからyにいく時のコストは2地点の標高差、
    // yからxにいく時は2地点の標高差となる
    // つまりコストだけを考えるようにしている
    // 登る時はコストを払う必要がある、登った分は下れるので実質コストはその標高差分だけある
    e[x].push_back({ y, max(h[y] - h[x], (long long)0) });
    e[y].push_back({ x, max(h[x] - h[y], (long long)0) });
  }
  // 辺までのコストを無限大に初期化
  for (int i = 0; i < n; i++)d[i] = INF;
  // 初期の到達コストは0
  d[0] = 0;
  ans = 0;
  // 初期のコストと始点をpush
  pq.push({ -d[0],0 });
  // n回ループ
  // コストを最小化する
  for (int i = 0; i < n; i++) {
    // 現時点でコストが低いものを取得
    p = pq.top();

    // 今見ている頂点への最短距離が
    // 現時点までのコストよりも短い場合は探索しない
    while (d[p.second] < -p.first) {
      pq.pop();
      p = pq.top();
    }
    pq.pop();
    // 頂点番号
    k = p.second;
    // 初期地点の高さ-現時点の高さ-ここまでの距離
    // 答えを更新
    ans = max(ans, h[0] - h[k] - d[k]);
    // 今の頂点に繋がっている辺を探索
    for (int i = 0; i < e[k].size(); i++) {
      // これから探索する頂点までのコストが、今の頂点から移動した場合より大きい場合探索
      if (d[e[k][i].first] > (d[k] + e[k][i].second)) {
        // コスト更新
        d[e[k][i].first] = d[k] + e[k][i].second;
        // 次の探索候補に追加
        pq.push({ -d[e[k][i].first], e[k][i].first });
      }
    }
  }
  cout << ans << endl;
  return 0;
}