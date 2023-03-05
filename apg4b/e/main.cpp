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

int main(){
  int n;
  cin >> n;
  vector<long long> a(n+1),b(n+1,0);
  for(int i=1;i<=n;i++){cin >> a[i];}
  // 休日同士がi日である部分において間に挟まる平日の生産量の総和
  for(int i=1;i<=n;i++){b[i]=b[i-1]+a[(i+1)/2];}
  vector<vector<long long>> dp(n+1,vector<long long>(n+1,-4e18));
  // dp[何曜日まで割り当てを決めたか][現在連続している平日の数] = {生産量の最大値}
  // 曜日1を休日に固定する
  // 逆に言えば固定しても答えは問題なく求めることができる
  dp[1][0]=0;
  for(int i=1;i<n;i++){
    // 平日は最低0日、最大n日連続する
    for(int j=0;j<=n;j++){
      // 今の場所に遷移できなければcontinue
      if(dp[i][j]<0){continue;}
      // 次の日まで割り当てを決めて次の日が平日なので、今の値と遷移先の値の大きい方を記録
      dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]);
      // 次の日まで割り当てを決めて次の日が休日なので、間に挟まる平日の生産量の総和を足している
      dp[i+1][0]=max(dp[i+1][0],dp[i][j]+b[j]);
    }
  }
  debug(dp);
  long long res=0;
  // 最後の「休日」から最初の「休日」( 曜日 1 ) までの区間を考慮することに対応
  for(int i=0;i<n;i++){
    // 最後の時点でi日間平日が続いているので、最初に戻るまでの日数分の生産量を足す
    res=max(res, dp[n][i]+b[i]);
  }
  cout << res << "\n";
  return 0;
}