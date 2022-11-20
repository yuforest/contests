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

int main(){
  vector<ll> ten(18);
  ten[0] = 1;
  // 下の操作が終わった後の初期状態でこの配列は1,10,100,1000...のようになっている
  rep(i,17) ten[i+1] = ten[i] * 10;

  int t;
  cin >> t;

  // 101や
  rep(i,t) {
    ll n;
    cin >> n;
    int len = to_string(n).size();
    // 少なくとも1桁下の9... は周期的な数になる
    // これがNの一桁下の数字までの最大値となる
    ll ans = ten[len-1] - 1;

    // よって後はNと同じ長さの数字の最大値を調べれば良い
    // jは1つの周期の長さを表している
    // 最低2回はセットを繰り返す必要があるので最大値はlen/2
    for (int j = 1; j <= len/2; j++){
      // 割り切れなければskip
      // 周期的な数にならないため
      if (len % j) continue;

      ll q = 0;
      // len/jは周期が繰り返される回数
      // その回数分だけqに足し上げている
      // N=1412、len=4、j=2の時
      // q = ten[0] + ten[2] = 1 + 100 + 10000 = 101となる
      // j=1の時
      // q=ten[0] + ten[1] + ten[2]+ten[3] = 1111となる
      rep(k, len/j) {
        q += ten[k * j];
      }
      debug(q);
      // 1412/101 * 101 = 13*101 = 1313となる
      // n / qはnの中にqがいくつ収まるかを表す
      ll p = n / q * q;
      debug(p);
      ans = max(ans, p);
    }
    cout << ans << endl;
  }
  return 0;
}