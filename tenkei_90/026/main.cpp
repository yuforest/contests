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
int N;
int A[1 << 18], B[1 << 18];

// Graph
int col[1 << 18];

void dfs(int pos, int cur) {
  col[pos] = cur;
  for (int i : G[pos]) {
    // 既に彩色済みならcontinue
    if (col[i] >= 1) continue;
    // 3-curをすると1か2でグラフを彩色することになる
    dfs(i, 3 - cur);
  }
}

int main() {
  // Step #1. Input
  cin >> N;
  for (int i = 1; i <= N - 1; i++) {
    cin >> A[i] >> B[i];
    G[A[i]].push_back(B[i]);
    G[B[i]].push_back(A[i]);
  }

  // Step #2. Graph Coloring
  dfs(1, 1);

  // Step #3. Get Answer
  vector<int> G1, G2;
  for (int i = 1; i <= N; i++) {
    if (col[i] == 1) G1.push_back(i);
    if (col[i] == 2) G2.push_back(i);
  }
  // 大きいサイズの頂点をN/2個だけ出力すれば良い
  if (G1.size() > G2.size()) {
    for (int i = 0; i < (N / 2); i++) {
      if (i) cout << " ";
      cout << G1[i];
    }
    cout << endl;
  }
  else {
    for (int i = 0; i < (N / 2); i++) {
      if (i) cout << " ";
      cout << G2[i];
    }
    cout << endl;
  }
  return 0;
}