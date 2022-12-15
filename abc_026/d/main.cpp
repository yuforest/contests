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

ll A, B, C;
const double PI = acos(-1.0);
double f(double t) {
  return A*t + B * sin(C*t*PI);
}

int main() {
  cin >> A >> B >> C;
  // 100 = At + Bsin(Ctπ)
  // -1 <= sin(x) <= 1
  // -B <= Bsin(x) <= B
  // この関数はA,B,Cが正でなので右肩上がりの直線にsinの曲線が合わさったものになりそう
  // 二分探索だとsin部分が邪魔になって解けないかも->f(t)はtに対して連続であるので
  // f(x1)<=100<=f(x2)の時x1とx2の間に必ずf(t)=100となるtが存在する(平均値の定理)
  double low = 0;
  // このとき絶対f(high)>=100
  double high = 200;
  rep(i, 10000) {
    // 誤差が十分に小さくなったらbreak
    if (abs(f(low)-100) < 1e-12) break;
    double mid = (low+high) / 2;
    debug(f(mid));
    // lowとhighの中間が100より小さければ左側を右に詰める
    if (f(mid)<100) low = mid;
    // 100以上であれば右側を左に詰める
    else high = mid;
    // 上記の過程を行う中でlowとhighは探索範囲を狭めつつも1つの解もその範囲内に含まなくなって
    // しまうことはなく結果として十分な回数探索を行うことで限りなく近い階を求めることができる
  }
  cout << fixed << setprecision(18) << low << endl;
  return 0;
}