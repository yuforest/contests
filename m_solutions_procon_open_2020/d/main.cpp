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
// usng namespace atcoder;

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


template<typename T>T min(const vector<T>&v){return *min_element(v.begin(),v.end());}
template<typename T>T max(const vector<T>&v){return *max_element(v.begin(),v.end());}
template<typename T>T acc(const vector<T>&v){return accumulate(v.begin(),v.end(),T(0));};
template<typename T>T reverse(const T &v){return T(v.rbegin(),v.rend());};

// DPやlong longの最大値最小値更新で重宝します。
template <typename T>
inline bool chmax(T &a, T b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T>
inline bool chmin(T &a, T b) {
  return ((a > b) ? (a = b, true) : (false));
}

// 貪欲法で解ける
// int main() {
//   ll N;
//   cin >> N;
//   ll A[N];
//   rep(i, N) cin >> A[i];
//   ll money = 1000;
//   rep3(i, 1, N) {
//     if (A[i] <= A[i-1]) continue;
//     ll count = money / A[i-1];
//     money -= A[i-1] * count;
//     money += count * A[i];
//   }
//   cout << money << endl;
// }


// DPでも解ける
long long N, A[87];
long long dp[87];

int main() {
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> A[i];
  // dp[x]： x日目に、株の売却が終了した時点の所持金の最大値。
  dp[1] = 1000;
  // 株を売る日を全探索(初日以外)
  for (int i = 2; i <= N; i++) {
    // 1日前の金額を入れる
    dp[i] = dp[i - 1];
    // 株を買う日を全探索(i-1日目まで)
    // iの前日までで株を買う日を全探索
    for (int j = 1; j <= i - 1; j++) {
      // j日目に株を買った場合何株買えるか
      long long V = dp[j] / A[j];
      // i日目に売った場合j日目の所持金と比べてどれだけ増えるか
      long long W = dp[j] + (A[i] - A[j]) * V;
      // 最大値更新
      dp[i] = max(dp[i], W);
    }
  }
  cout << dp[N] << endl;
  return 0;
}