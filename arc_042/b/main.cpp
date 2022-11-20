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


// 2点と通る直線の一般系ax + by + c = 0の値をtupleにまとめて返す
tuple<double, double, double> two_point_line(double x1, double y1, double x2, double y2) {
  return make_tuple(y2-y1, x1 - x2, x2 * y1 - x1 * y2);
}

// 点と直線の距離を計算する
double point_line_distance(double x0, double y0, tuple<double, double, double> line) {
  return abs(get<0>(line)*x0 + get<1>(line)*y0 + get<2>(line)) / sqrt(get<0>(line)*get<0>(line) + get<1>(line)*get<1>(line));
}

int main() {
  double x0, y0;
  cin >> x0 >> y0;
  ll N;
  cin >> N;
  double x[N], y[N];
  rep(i, N) {
    cin >> x[i] >> y[i];
  }
  double ans = 1000;
  rep(i, N) {
    double dist;
    if (i == N-1) {
      dist = point_line_distance(x0, y0, two_point_line(x[i], y[i], x[0], y[0]));
    } else {
      dist = point_line_distance(x0, y0, two_point_line(x[i], y[i], x[i+1], y[i+1]));
    }
    debug(dist);
    chmin(ans, dist);
  }
  cout << fixed << setprecision(18) << ans << endl;
}