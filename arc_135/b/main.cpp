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

// N=5
// S[]=6 9 6 6 5

// 5. 差分を出してみる。

// id: 0   1   2   3   4   5   6
// S:          6   9   6   6   5
// S1-S0:         +3  -3   0  -1
// A:  a   b   c  a+3 b-3  c  a+3-1 ...
//    ~~~        ~~~~~       ~~~~~~~
//    A0          A3           A6
//              = S1-S0      = S4-S3

// 7.
// a)A0,A3,A6を求める
// A[0] = 0 // 仮に0を置く。
// A[3] = 3
// A[6] = 2
// が入る。
// 最小値は0なので、A0,A3,A6に補正はいらない。

// b)A1,A4を求める

// A[1] = 0 // 0を仮入れ
// A[4] = -3
// 最小値は -3 だが、A>=0 でないといけないので、+3の補正を行う。

// A[1] = 0+3
// A[4] = -3+3

// c)A2,A5を求める

// A[2] = 0
// A[5] = 0

// これで、
// A[0] = 0
// A[1] = 3
// A[2] = 0
// A[3] = 3
// A[4] = 0
// A[5] = 0
// A[6] = 2
// が求まる。

// 8. S[0] = 6 に合わせる。
// A0+A1+A2 = 3なので、6-3の+3が調整値。

// A0, A3, A6,...の差分さえあっていればいいので、
// A[0] = 0+3
// A[1] = 3
// A[2] = 0
// A[3] = 3+3
// A[4] = 0
// A[5] = 0
// A[6] = 2+3

// これが答え。

ll S[300030];
ll A[300030];
ll N;

void init_A(ll s){
  ll now = 0;
  ll low = 0;
  for(ll i=s; i<N; i+=3){
    now += S[i]-S[i-1];
    A[i+2] = now;
//    cout << "A[" << i+2 << "]:" << A[i+2] << endl;
    chmin(low, now);
  }
  for(ll i=s-3; i<N; i+=3){
    A[i+2] += abs(low);
  }
}

int main(){

  cin >> N;
  rep(i, N){
    cin >> S[i];
  }
  // 1-0, 4-3
  init_A(1);
  init_A(2);
  init_A(3);
  ll add = S[0] - (A[0]+A[1]+A[2]);
  if (add < 0){
    cout << "No" << endl;
    return 0;
  }
//  cout << "add:" << add << endl;
  cout << "Yes" << endl;
  rep(i, N+2){
    if (i%3 == 0){
      A[i] += add;
    }
    cout << A[i];
    if (i<N+1) cout << " ";
    else cout << endl;
  }
}