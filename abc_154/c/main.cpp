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

long long mod = 1000000007;
vector<ll> G[1 << 18];
// vvl G(1000000009, vl());

// ACLです。使わない時はコメントアウトしています。導入方法はググってみてください。
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
const ll INF = ll(1e18);

// int main() {
//   string S;
//   cin >> S;
//   ll ans = 0;
//   ll digit = 1;
//   reverse(S.begin(), S.end());
//   rep(i, S.size()) {
//     ans += (S[i] - 'A' + 1) * digit;
//     digit *= 26;
//   }
//   cout << ans << endl;
// }


int main()
{
  string S;
  cin >> S;

  int size = S.length();

  string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  map<char, int> mp; // アルファベットと数字の対応
  for (int i = 0; i < alphabet.length(); i++)
  {
    mp[alphabet[i]] = i + 1; // A:1, B:2,,,,Z: 26
  }

  long long result = 0;
  for (int i = 0; i < size; i++)
  {
    int targetKeta = size - i;
    char s = S[i];
    result += 1LL * powl(26, targetKeta - 1) * mp[s];
  }
  float val0 = 1;
  auto val = pow(2.0, 3.0);
  debug(val);

  cout << result << endl;
}