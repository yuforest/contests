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


// O(NlogN)
template<class T> int LIS(vector<T> a,  bool is_strong = true) {
  const T INF = 1<<30; // to be set appropriately
  int n = (int)a.size();
  vector<T> dp(n, INF);
  for (int i = 0; i < n; ++i) {
    if (is_strong) *lower_bound(dp.begin(), dp.end(), a[i]) = a[i];
    else *upper_bound(dp.begin(), dp.end(), a[i]) = a[i];
  }
  return lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
}

// 隣接する (Ai,Bi) と (Ai+1,Bi+1) を何度でもスワップできるということは，
// N 個の組 (Ai,Bi) を自由な順に並べ替えられるということになる
// つまりこの組を並び替えたあと、A,Bに印をつけてそれがそれぞれ単調増加になっている必要がある
// 最適解のうちで，すべての Aiに印がついているものが存在する
// まずどちらにも印がついていないiがあればAi,Biの組を適切な位置に挿入してAiに印をつけることで
// 印の個数を増やすことができる
// よって最適解では任意のiでAiかBiに印がついている
// Aiに印がついていない最適解がある場合、これを適切な位置に挿入してBiの印を削除して
// 代わりにAiに印をつけることで印の個数を悪化(減少)させずにAiについている印の個数を
// 増やすことができる
int main() {
  int N;
  cin >> N;
  // AとBをまとめて保存しておくペアの配列
  vector<pair<int, int>> AB(N);
  for (int i = 0; i < N; ++i) cin >> AB[i].first;
  for (int i = 0; i < N; ++i) cin >> AB[i].second;
  // Aが昇順に並ぶようにソート
  sort(all(AB));
  // ソートした時のBの値を保存
  vector<int> B(N);
  for (int i = 0; i < N; ++i) B[i] = AB[i].second;
  // このときの LIS(A)+LIS(B)=N+LIS(B) が答
  cout << N + LIS(B) << '\n';

  return 0;
}