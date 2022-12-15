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


ll N, K, w[1000], p[1000];
// 目標パーセンテージの食塩水が作れるかどうか
bool check(double mid) {
  vector<double> t;
  rep(i, N) {
    // (i番目の食塩水に含まれる食塩の量*100)-(midの濃さの食塩水をw[i]g作った時に必要になる食塩の量*100)
    // (パーセンテージ*食塩水の量を100で割っていないので)
    // t[i]の値がプラスであれば、この食塩水は目標の濃さの食塩水よりも濃い
    // あるパーセンテージ以上の濃さの食塩水を作ろうとした時に、この食塩水がどれだけ寄与するか、
    // もしくは損害を与えるかということがわかる
    // K個選んだときの累計の食塩量がマイナスにならなければ良い
    // どれを優先して選ぶべきかという優先度をここで決めることができる
    double val = (1.0 * p[i] * w[i]) - (mid * w[i]);
    t.push_back(val);
  }
  // 大きい順にソート
  sort(t.begin(),t.end(), greater<double>());
  debug(t);
  double sum = 0.0;
  // 大きいものからK個選んでマイナスにならなければその濃さの食塩水は作成可能
  rep(i, K) {
    sum += t[i];
  }
  debug(sum);
  return sum >= 0.0;
}

// 「平均の最大化問題」を解くには「答えを先に決めてしまう二分探索」が非常に有効
// 特定パーセンテージ以上は達成できるか、できないかという問題の結果により
// 範囲を狭めていくことができる
int main() {
  cin >> N >> K;
  rep(i, N) {
    cin >> w[i] >> p[i];
  }
  double ng = 0;
  double ok = 100;
  // 解の範囲は1/2ずつ狭まっていくので100回もやれば十分
  // 最初の範囲は100
  // 次以降50,25,12.5,6,3,1.5,0.75,0.3,0.15,0.07...
  // 10回時点で誤差10^(-2)程度までこれる
  // 100*(1/2)^100=7.8e-29
  // ngとokは限りなく近づくのでどちらを選んでも問題ない
  rep(i, 100) {
    double mid = (ng + ok) / 2;
    if (check(mid)) ng = mid;
    else ok = mid;
  }
  cout << fixed << setprecision(10) << ok << endl;
  return 0;
}

