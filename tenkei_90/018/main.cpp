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

const double pi = acos(-1);

int main() {
  double t,l,x,y;
  cin >> t >> l >> x >> y;
  int q;
  cin >> q;
  while(q--) {
    double e;
    cin >> e;
    // e/t周している、つまりe/t*360度回っている
    // よってその割合に2πをかければ、θを求められる
    double theta = e/t*pi*2;
    // 観覧車のy座標は、1/4周した時に最も小さくなり3/4周した時に最も大きくなる
    double ty = -l/2*sin(theta);
    // 観覧車のz座標は、始点で最も小さくなり1/2周した時に最も大きくなる
    double tz = l/2-l/2*cos(theta);
    // 観測地点と銅像の水平距離、三平方の定理で求めることができる
    double a = sqrt(x*x + (y-ty)*(y-ty));
    // 高さ
    double b = tz;
    // 度数法に直して出力
    printf("%.15f\n",(double)atan2(b,a)*180/pi);
  }
  return 0;
}