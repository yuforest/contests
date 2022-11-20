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

int ans[2010];

// int main() {
// 	double p;
// 	cin >> p;
//   // y = 2^(x/1.5)の導関数
//   // これが0になる時のxを求める
//   // 負の場合はいますぐ計算を始めるのが最速
// 	double x = 3.0/2.0*log2(2.0/3.0*p*log(2));
// 	double ans;
// 	if(x>=0){
// 		ans=x+p/(pow(2.0,2.0/3.0*x));
// 	}else{
// 		ans=p;
// 	}
// 	cout << fixed <<setprecision(18) << ans << endl;
//   return 0;
// }


double p;
double func(double x) {
  return p / pow(2, x / 1.5) + x;
}
// 三分探索でも解ける
int main() {
  cin >> p;
  double lb = 0;
  double ub = 1e9;

  while (ub - lb > 1e-7) {
    // 待つ時間を計算(1/3地点と2/3地点)
    // 凸関数の極値を求めることができる
    double c1 = lb + (ub - lb) / 3.0;
    double c2 = lb + (ub - lb) / 3.0 * 2.0;
    // もしf(c2)のほうが良い(小さい)なら、駄目な方lowを更新する
    if (func(c1) > func(c2)) {
        lb = c1;
    } else {
        ub = c2;
    }
  }

  cout << setprecision(15) << func(lb) << endl;

  return 0;
}