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

// N=(−2)q+r
// としたときに、r が 0 か 1 になるように q を調節するということになります。これ実は、
// N が偶数なら r=0
// N が奇数なら r=1
// すればよいという感じなので、実は N を単に 2 で割るのと変わらない
// N  % 2 の値は 0 か -1 になってしまうので、-1 になるならそれに 2 を足す
int main() {
  int N; cin >> N;
  string str = "";
  while (N != 0) {
    /* N を 2 で割ったあまりを求める */
    // フラグが立つのはrが0以外になる時
    // 現在見ている桁の一つ上の桁を考えた時に余りが出るかどうか
    int r = N % 2;
    if (r < 0) r += 2; // N がマイナスだと r がマイナスになったりするので 2 を足す

    /* 答えに追加、下の桁から追加していく */
    str += (char)('0' + r);

    /* N から余りを取り除いて -2 で割る */
    N = (N - r) / (-2);

  }
  /* 向きが逆なので反転 */
  reverse(str.begin(), str.end());
  if (str == "") str = "0"; // N = 0 のときは空文字列になってしまうので例外処理
  cout << str << endl;
}