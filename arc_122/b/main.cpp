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


// int main() {
//   int N;
//   cin >> N;
//   vector<double> A(N);
//   rep(i, N) cin >> A[i];
//   sort(A.begin(), A.end());
//   double x;
//   if (N % 2 == 0) {
//     x = (A[N/2] + A[N/2-1]) / 4.0;
//   } else {
//     x = A[N/2] / 2.0;
//   }

//   double ans = 0;
//   rep(i, N) {
//     ans += x + A[i] - min(A[i], 2 * x);
//   }
//   ans /= N;
//   cout << fixed << setprecision(18) << ans << endl;


//   return 0;
// }


// 三分探索による解
int n;
double arr[100002];

// O(N)の計算量
double cost(double x){
  double ret = 0;
  for(int i=1; i<=n; i++){
    ret += x + arr[i] - min(arr[i], x+x);
  }
  ret /= n;
  return ret;
}

int main(){
  scanf("%d", &n);
  for(int i=1; i<=n; i++) scanf("%lf", &arr[i]);
  sort(arr+1, arr+n+1);

  double l = 0, r = 1000000000;
  // この関数は下に凸なので三分探索により近似値を求められる
  // 操作の度に範囲は1/3になっていくので100回も行えば十分な精度で求められる
  for(int i=0; i<=100; i++){
    // lとrの区間の間でlよりの値と、rよりの値の2つを作る
    // つまりlとrの区間を三分する
    double p = (l+l+r) / 3;
    double q = (l+r+r) / 3;
    // それら二つに対してコストを計算する
    double pc = cost(p), qc = cost(q);
    // lよりの値の方がコストが小さければ、
    // 最小値はqよりも左側にあるのでrをqに移動させる
    if(pc < qc) r = q;
    // rよりの値の方がコストが同じか小さければ
    // 最小値はpかそれより右側にあるのでlをpに移動させる
    else l = p;
  }
  cout << fixed << setprecision(18) << cost(l) << endl;
}