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

// int main() {
//   ll N;
//   string S;
//   cin >> N >> S;
//   ll ans = 0;
//   ll l = 0;
//   map<char, ll> mp;
//   rep(r, N) {
//     mp[S[r]]++;
//     while(mp['o'] > 0 && mp['x'] > 0) {
//       ans += (N-r);
//       mp[S[l]]--;
//       l++;
//     }
//     debug(mp);
//     debug(ans);
//   }
//   cout << ans << endl;
// }

long long N;
string S;
vector<pair<char, long long>> vec;

int main() {
  cin >> N >> S;

  // ランレングス圧縮する
  long long cnt = 0;
  for (int i = 0; i < S.size(); i++) {
    cnt++;
    if (i == (int)S.size() - 1 || S[i] != S[i + 1]) {
      vec.push_back(make_pair(S[i], cnt));
      cnt = 0;
    }
  }

  // 同文字しか含まれない区間の総数が余事象となる
  long long ret = 0;
  for (int i = 0; i < vec.size(); i++) {
    // 同じ文字しか含まれない区間の数を計算する
    // di個同じ文字が連続しているとすると
    // di + di-1 + ... + 1個が区間の数になるので
    // 等差数列の和の公式により求めることができる
    // 1からNまでの和は N(N+1)/2
    ret += 1LL * vec[i].second * (vec[i].second + 1LL) / 2LL;
  }
  // 余事象の分を引く
  cout << N * (N + 1) / 2LL - ret << endl;
  return 0;
}