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
int gcd(int x, int y) { return (x % y)? gcd(y, x % y): y; }

int main() {
  ll N, L;
  cin >> N >> L;
  ll a[N];
  rep(i, N) cin >> a[i];
  ll last_two = -1;
  for(ll i = N-1; i >= 0; i--) {
    if(a[i] == 2) {
      last_two = i;
      break;
    }
  }
  // 全て1人なら確実に座ることができる
  if(last_two == -1) {
    cout << "Yes" << endl;
    return 0;
  }
  // 0番目からL-1までの座席がある
  vl seats(L);
  ll current = 0;
  rep(i, N) {
    debug(current);
    if (i == last_two) {
      if (current + 2 <= L) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
      break;
    }
    if (a[i] == 1) {
      current += 2;
    } else {
      current += 3;
    }
  }


}