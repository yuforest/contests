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
  // Bは現在の街まで訪問した時の金の最安値を保存する配列
  // dp[i] : 街iに到達できる街 (街 i 自身を含まない) における金の最安値
  vector<int> A(N), B(N, INT_MAX);
  for(int& a : A) cin >> a;
  // グラフを受け取る二次元配列
  vector<vector<int>> g(N);
  while(M--){
    int X, Y;
    cin >> X >> Y;
    X--; Y--;
    // 単方向グラフ
    g[X].push_back(Y);
  }
  int ans = INT_MIN;
  // 0からN-1までを順番に訪問
  // Xi < Yiなので閉路ができることはなく、小さい街から大きい街にしか行けない
  // 大きい街から小さい街に戻ることはない
  // このグラフは DAG (Directed Acyclic Graph, 閉路を含まない有向グラフ)になっている
  for(int i = 0; i < N; i++){
    // 利益の最大値を更新
    // 買った街で売ることはできないから最初に利益の更新を行う
    chmax(ans, A[i] - B[i]);
    // この街の金価格でこの街まで訪問した時の金価格の最小値を更新
    chmin(B[i], A[i]);
    // この街から行ける街の金価格の最小値を現在の街の金価格の最小値で更新
    for(int j : g[i]) chmin(B[j], B[i]);
    debug(i);
    debug(ans);
    debug(B);
  }
  cout << ans << endl;
  return 0;
}