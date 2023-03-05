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
using vvvl = vector<vector<vector<ll>>>;
using pii = pair<int, int>;

long long mod = 1000000007;
// vector<ll> G[1 << 18];

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

// int main() {
//   ll N, X;
//   cin >> N >> X;
//   vl A, B;
//   rep(i, N){
//     int a, b, c=1;
//     cin >> a >> b;
//     // divide m into 1, 2, 4, 8...
//     while(c<=b){
//       A.push_back(a*c);
//       if (b > 0) B.push_back(1);
//       else B.push_back(0);
//       b -= c;
//       c *= 2;
//     }
//     // the rest of m
//     if(b>0){
//       A.push_back(a*b);
//       if (b > 0) B.push_back(1);
//       else B.push_back(0);
//     }
//   }
//   debug(A);
//   debug(B);
//   ll M = A.size();
//   vvl dp(M+1, vl(X+1, 0));
//   dp[0][0] = 1;
//   rep(i, M) {
//     rep(j, X+1) {
//       // 今の金額は次でも選ばないことによって実現できる
//       chmax(dp[i+1][j], dp[i][j]);
//       // 金額の遷移が可能なとき遷移する
//       if(j >= A[i] && B[i] != 0)  {
//         // j-A[i]円が実現可能ならj円も実現可能
//         chmax(dp[i+1][j], dp[i][j-A[i]]);
//       }
//     }
//   }
//   debug(dp);
//   if (dp[M][X] > 0) cout << "Yes" << endl;
//   else cout << "No" << endl;
// }

int main(void){
  int n,x;
  int a[50];
  int b[50];
  // n種類まで見た時に該当金額を作ることができるか
  bool dp[51][10001];
  cin>>n>>x;
  for(int i=0;i<n;i++)cin>>a[i]>>b[i];
  for(int i=0;i<=n;i++)for(int j=0;j<=x;j++)dp[i][j]=false;
  dp[0][0]=true;
  // n種類の硬貨
  for(int i=0;i<n;i++){
    // 金額を全探索
    for(int j=0;j<=x;j++){
      // b[i]個を全探索
      for(int k=0;k<=b[i];k++){
        // jが今回遷移したい金額より大きくて、遷移可能なら遷移する
        if(j>=a[i]*k){
          if(dp[i][j-a[i]*k])dp[i+1][j]=true;
        }
      }
    }
  }
  if(dp[n][x])cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}