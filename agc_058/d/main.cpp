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

const ll INF = 1e18;

vector<ll>dx={1,-1,0,0,1,1,-1,-1};
vector<ll>dy={0,0,1,-1,1,-1,1,-1};


// int main(){
//   ll n;
//   cin>>n;
//   ll sz = 100005;

//   vvl s(sz, vector<ll>(5, 0LL));
//   rep(i,n) {
//     ll t,x,a;
//     cin >> t >> x >> a;
//     s[t][x] += a;
//   }
//   // このようにしておけば遷移できないところに値を足したとしてもマイナスになる
//   // 10^6 * 10^6としても高々10^12
//   vvl dp(sz, vector<ll>(5, -INF));
//   dp[0][0] = 0;
//   // 時間と座標で全探索、渡すDP
//   // この書き方だと本来遷移できない場所にも遷移してしまうが、足される値よりも
//   // 元々の値の方が大きいので、0以上にならない
//   // 結果、0から遷移できる場所のみが残る
//   rep(i,sz-1) {
//     rep(j,5) {
//       // iの時間にi,jにいる時価値が増える
//       dp[i][j] += s[i][j];
//       // 右端以外にいる時は時間が1増えて右に遷移できる
//       if(j<4) chmax(dp[i+1][j+1], dp[i][j]);
//       // 次の時間まで現在の座標にとどまる
//       chmax(dp[i+1][j],dp[i][j]);
//       // 左端以外にいるときは時間が1増えて左に遷移できる
//       if(j>0) chmax(dp[i+1][j-1],dp[i][j]);
//     }
//   }
//   cout<< max(dp[sz-1]) << endl;
//   return 0;
// }

int main() {
  ll n;
  cin >> n;
  vvl events(100007, vector<ll>(5, 0LL));
  rep(i, n) {
    ll t, x, a;
    cin >> t >> x >> a;
    events[t][x] = a;
  }
  vvl dp(100007, vector<ll>(5, -INF));
   dp[0][0] = 0;
  rep3(i, 0, 100006) {
    rep(j, 5) {
      dp[i][j] += events[i][j];
      if (j != 4) chmax(dp[i+1][j+1], dp[i][j]);
      chmax(dp[i+1][j], dp[i][j]);
      if (j != 0) chmax(dp[i+1][j-1], dp[i][j]);
    }
  }
  cout << max(dp[100006]) << endl;
}

