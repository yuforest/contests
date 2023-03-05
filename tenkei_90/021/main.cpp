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
#define per3(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) per3(i, 0, b)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(), (x).end()

// 無くても困らない
#define INFTY (1 << 30)

// 浮動小数点の誤差を考慮した等式ですが、使わずに済むなら使わない方が確実です
#define EPS (1e-7)#define equal(a, b) (fabs((a) - (b)) < EPS)

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

// Input
int N, M;
int A[1 << 18], B[1 << 18];

// Graph
bool used[1 << 18];
// vector<int> G[1 << 18];
vector<int> H[1 << 18];
vector<int> I;
long long cnts = 0;

// 帰りがけ順に番号を記録
void dfs(int pos) {
  used[pos] = true;
  for (int i : G[pos]) {
    if (used[i] == false) dfs(i);
  }
  I.push_back(pos);
}

// 辺を反転させたグラフを探索
void dfs2(int pos) {
  used[pos] = true;
  // 強連結な頂点を数える
  cnts++;
  for (int i : H[pos]) {
    if (used[i] == false) dfs2(i);
  }
}

int main() {
  // Step #1. Input
  cin >> N >> M;
  for (int i = 1; i <= M; i++) {
    cin >> A[i] >> B[i];
    G[A[i]].push_back(B[i]);
    // 反転させたグラフ
    H[B[i]].push_back(A[i]);
  }

  // Step #2. First DFS
  // 連結とは限らない
  for (int i = 1; i <= N; i++) {
    // 未探索の場合dfs
    if (used[i] == false) dfs(i);
  }

  // Step #3. Second DFS
  // 強連結成分を一つの頂点に潰すとDAGになるが、
  // このとき番号が一番大きい頂点(帰りがけ順の最後)というのは
  // DAGの先頭の強連結成分(最初の強連結成分)に属していることがわかる。
  // 辺を逆向きにすると、この先頭の強連結成分から外に出ることができなくなる。
  long long Answer = 0;
  // 反転、
  reverse(I.begin(), I.end());
  // 未使用に戻す
  for (int i = 1; i <= N; i++) used[i] = false;
  for (int i : I) {
    if (used[i] == true) continue;
    // リセット
    cnts = 0;
    dfs2(i);
    // 頂点がcnts個からなる場合、そこから2個選ぶのでcntC2の合計が答え
    Answer += cnts * (cnts - 1LL) / 2LL;
  }

  // Step #4. Output The Answer!
  cout << Answer << endl;
  return 0;
}