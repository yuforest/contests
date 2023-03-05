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

// 各桁の合計
int digit_sum(int x) {
  int ans = 0;
  while (x > 0) {
    ans += x % 10;
    x /= 10;
  }
  return ans;
}
int main() {
  const int mod = 100000;
  int N; long long K;
  cin >> N >> K;
  // 今の数字に各桁の和を足して、あまりを取ったものをnxt[i]に入れる
  // 今の数字がiであるときの次の数字
  vector<int> nxt(mod);
  for (int i = 0; i < mod; ++i) {
    nxt[i] = (i + digit_sum(i)) % mod;
  }
  // 最初の数字から周期性を考える
  vector<int> time_stamp(mod, -1);
  // cntはループを抜けるまでの移動回数
  int pos = N, cnt = 0;
  while (time_stamp[pos] == -1) {
    // 今の移動回数を入れておく、0スタート
    time_stamp[pos] = cnt;
    pos = nxt[pos];
    ++cnt;
  }
  // サイクルを求める、移動の合計回数からそこに最初にくるまでの移動回数を引く
  int cycle = cnt - time_stamp[pos];
  debug(cnt);
  debug(time_stamp[pos]);
  debug(cycle);
  // Kがそこに最初に来るまでの移動回数より多いとき
  if (K >= time_stamp[pos]) {
    // 最初の移動か良い数を引いた上であまりを求める、これはサイクル上でのどの位置にいるかを表す
    // そこにサイクルに入るまでの最初からの移動回数を足す
    K = (K - time_stamp[pos]) % cycle + time_stamp[pos];
  }
  debug(K);
  int answer = -1;
  // 0からmodまで見ればよい
  for (int i = 0; i < mod; ++i) {
    // 移動回数がKの時のiが答えとなる、サイクルに入ってから何周かして同じ位置にくる
    // というループを省略できる
    if (time_stamp[i] == K) {
      answer = i;
    }
  }
  cout << answer << endl;
  return 0;
}