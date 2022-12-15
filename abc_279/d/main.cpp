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

typedef long double ld;
const ld eps = 1.0e-18; // 許容される誤差

ld mysqrtl(ld x)
{
  ld a = sqrt((double)x); // 近似値
  do {
    a = (a + x/a) / 2.0L;
  } while (fabsl(x - a*a) > eps);
  return a;
}

ld A, B;
// gの値
ld func(ld g) {
  return (A / sqrt(g)) + (B * (g - 1));
}

int main() {
  cin >> A >> B;
  ll lb = 0;
  ll ub = 1e18 + 4;
  cout << fixed << setprecision(10);

  while (true) {
    debug(lb);
    debug(ub);
    if (lb + 1 >= ub) break;
    // 待つ時間を計算(1/3地点と2/3地点)
    // 凸関数の極値を求めることができる
    ll c1 = lb + (ub - lb) / 3;
    ll c2 = lb + (ub - lb) / 3 * 2;
    // debug(c1);
    // debug(c2);
    debug(lb);
    debug(ub);
    // もしf(c2)のほうが良い(小さい)なら、駄目な方lowを更新する
    if (func(c1) > func(c2)) {
      lb = c1;
    } else {
      ub = c2-1;
    }
  }
  cout << func(lb+1) << endl;
  return 0;
}