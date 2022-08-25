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

int ans[2010];

// DPで解ける
// int main() {
//   int N, K;
//   cin >> N >> K;
//   int A[N+1], B[N+1];
//   rep(i, N) {
//     cin >> A[i+1];
//   }
//   rep(i, N) {
//     cin >> B[i+1];
//   }
//   // dp[i]->Xi = Aiとして良いか、ep[i] -> Xi = Biとして良いか
//   vector<ll> dp(N+1,false), ep(N+1,false);
//   //初期値
//   dp[1]=ep[1]=true;
//   //遷移
//   for(ll i=2;i<=N;i++){
//     // 前まで遷移できていれば次も遷移できる
//     if(dp[i-1]){
//       if(abs(A[i-1]-A[i])<=K) dp[i]=true;
//       if(abs(A[i-1]-B[i])<=K) ep[i]=true;
//     }
//     // 前まで遷移できていれば次も遷移できる
//     if(ep[i-1]){
//       if(abs(B[i-1]-A[i])<=K) dp[i]=true;
//       if(abs(B[i-1]-B[i])<=K) ep[i]=true;
//     }
//   }
//   //答え
//   if(dp[N] || ep[N])cout<<"Yes"<<endl;
//   else cout<< "No" << endl;
// }


int main() {
  int N, K;
  cin >> N >> K;
  int A[N], B[N];
  rep(i, N) {
    cin >> A[i];
  }
  rep(i, N) {
    cin >> B[i];
  }
  string ans = "Yes";
  bool before_A = true;
  bool before_B = true;
  rep(i, N-1) {
    bool next_A = false;
    bool next_B = false;
    if (before_A && abs(A[i] - A[i+1]) <= K) {
      next_A = true;
    }
    if (before_A && abs(A[i] - B[i+1]) <= K) {
      next_B = true;
    }
    if (before_B && abs(B[i] - A[i+1]) <= K) {
      next_A = true;
    }
    if (before_B && abs(B[i] - B[i+1]) <= K) {
      next_B = true;
    }
    bool can_move = next_A || next_B;
    if (!can_move) {
      ans = "No";
    }
    before_A = next_A;
    before_B = next_B;
  }
  cout << ans << endl;
  return 0;
}