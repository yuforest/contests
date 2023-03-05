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
#define per(i, b) per3(i, 0, b)
#define per3(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
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


string S;
// 2019で割ったあまりの数の個数を記録しておく
ll cnt[2020];

// 「連続する区間」についての問題は累積和的なものを取るのが定石
int main() {
  cin >> S;
  int N = S.length();

  ll ans = 0;
  cnt[0] = 1;
  int tot = 0;
  // 最初は1から始める
  int p = 1;
  // 文字を逆から見ていく
  // iを固定したときに条件を満たすjは「num[i] - num[j + 1]が2019の倍数」
  // num[i] - num[j + 1] = 0 (mod 2019)
  // num[i] = num[j + 1] (mod 2019)
  // 10で割るということは2と5で割るということであり
  // 3*673である2019の因数の個数には影響を与えない
  // iを固定してその後に出てくるあまりが同じとなるj+1で2019で割ったあまりが
  // 同じになるものの個数の和が答えとなる
  // 片方を固定してもう片方を高速に数え上げることができる
  per(i, N) {
    // 今の数字を構築して2019であまりを取る
    tot = (tot + (S[i] - '0') * p) % 2019;
    ans += cnt[tot];
    // 10を掛けて2019であまりを取る
    // 次の位にいくため
    p = (p * 10) % 2019;
    // 2019で割ったあまりを記録
    cnt[tot]++;
  }
  cout << ans << endl;
}