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
#include <atcoder/all>
using namespace atcoder;

// 競プロerはrepマクロが大好き
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep3(i,a,b) for(int i=a;i<b;i++)
#define per(i, b) per2(i, 0, b)
#define per3(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(), (x).end()

// 無くても困らない
#define INFTY (1 << 30)

// 浮動小数点の誤差を考慮した等式ですが、使わずに済むなら使わない方が確実です
#define EPS (1e-7)
#define equal(a, b) (fabs((a) - (b)) < EPS)

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

int main(){
  int N, M;
  cin >> N >> M;
  vector<int> A(N);
  vector<vector<int>> S(N);
  for (int i = 0; i < N; i++){
    cin >> A[i];
    S[i].resize(A[i]);
    for (int j = 0; j < A[i]; j++){
      cin >> S[i][j];
      S[i][j]--;
    }
  }
  vector<vector<int>> E(N + M);
  for (int i = 0; i < N; i++){
    for (int j = 0; j < A[i]; j++){
      // 超頂点に対して双方向の辺を張る
      // これは今の集合から、S[i][j]を含む集合に遷移できることを示している
      E[i].push_back(N + S[i][j]);
      E[N + S[i][j]].push_back(i);
    }
  }
  debug(E);
  // BFSする
  vector<int> d(N + M, -1);
  // Nは0番目の頂点を表している
  d[N] = 0;
  queue<int> Q;
  // スタートをpush
  Q.push(N);
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    // 繋がっている頂点を探索
    for (int w : E[v]){
      // 未探索なら距離を更新してpush
      if (d[w] == -1){
        d[w] = d[v] + 1;
        Q.push(w);
      }
    }
  }
  // 最後まで辿りつけなければ-1
  if (d[N + M - 1] == -1){
    cout << -1 << endl;
  } else {
    // 整数から集合に遷移し、整数に戻ってくるので2で割る
    cout << d[N + M - 1] / 2 - 1 << endl;
  }
}