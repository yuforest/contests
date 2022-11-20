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

// DPやlong longの最大値最小値更新で重宝します。
template <typename T>
inline bool chmax(T &a, T b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T>
inline bool chmin(T &a, T b) {
  return ((a > b) ? (a = b, true) : (false));
}

const long long INF = 1LL << 60; // 十分大きい値を 1 つ決める
int main(){
  ll N;
  cin >> N;
  vl H(N), S(N);
  rep(i, N) cin >> H[i] >> S[i];

  // 二分探索
  long long left = 0, right = INF;
  while (right - left > 1) {
    long long mid = (left + right) / 2;

    // 判定
    bool ok = true;
    vector<long long> t(N, 0); // 各風船を割るまでの制限時間
    for (int i = 0; i < N; ++i) {
      // そもそも mid が初期高度より低かったらfalse
      if (mid < H[i]) ok = false;
      // 少数切り捨てなのでt[i] <= x < t[i]の間で時間切れになる
      else t[i] = (mid - H[i]) / S[i];
    }
    // 時間制限がさし迫っている順にソート
    sort(t.begin(), t.end());
    // N-1秒までの時間経過を表している
    for (int i = 0; i < N; ++i) {
      // 秒数を超過しているので時間切れ
      if (t[i] < i) ok = false; // 時間切れ発生
    }
    // leftとその左側は条件を満たさない
    // rightとその右側は条件を満たす
    // 時間切れしなければright以上の高度は条件を満たすのでずらす
    if (ok) right = mid;
    // 時間切れしたら高度は現在のmidより高い必要があるので、ずらす
    else left = mid;
  }

  cout << right << endl;
  return 0;
}