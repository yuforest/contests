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
const ll INF = ll(1e18);

// maxi|NBi-MAi|の最小化問題を考える
// そのために定数xに対して
// maxi|NBi-MAi| <= x
// Biは非負整数でΣBi=Mを満たす
// ようなxは存在するかどうかの判定問題を考える
// |NBi-MAi| <= x ⇔ MAi-x <= NBi <= MAi+x ⇔ ceil((MAi-x)/N) <= Bi <= floor((MAi+x)/N)

long long K, N, M, A[1 << 19];
long long B[1 << 19];

int main() {
  cin >> K >> N >> M;
  for (int i = 1; i <= K; i++) cin >> A[i];
  // 仮にBiの値を計算する
  for (int i = 1; i <= K; i++) {
    // ここで切り捨てているのでB[i]の和は必ずMより小さくなる
    B[i] = M * A[i] / N;
    debug(B[i]);
  }

  // 仮の値を差し引いて残った分を計算する
  long long rem = M;
  vector<pair<long long, int>> vec;
  for (int i = 1; i <= K; i++) rem -= B[i];

  // Aは合計N人の元々の人口、BはM人の村に例えた時の人口
  for (int i = 1; i <= K; i++) {
    // sが大きくなるということは、M人の村に変更するための計算(M * A[i] / N)で
    // 切り捨てられた部分が大きいということ
    long long s = M * A[i] - N * B[i];
    vec.push_back(make_pair(s, i));
  }
  // vecをsが大きい順に並べる
  sort(vec.begin(), vec.end());
  reverse(vec.begin(), vec.end());
  debug(rem);
  debug(vec);
  // sが大きいものから余った分だけ1を足していく
  for (int i = 0; i < rem; i++) B[vec[i].second] += 1;

  // 出力
  for (int i = 1; i <= K; i++) {
    if (i >= 2) cout << " ";
    cout << B[i];
  }
  cout << endl;
  return 0;
}