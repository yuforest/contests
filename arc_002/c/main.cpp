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
const ll INF = ll(1e18);

int c[1010];
int dp[1010];

// 変換する文字を受け取ってdpで必要なボタンを押す回数をdpで計算する
int calc(int N, int l1, int l2, int r1, int r2){
  dp[0] = 0;
  dp[1] = 1;
  // ABABBABA
  for(int i = 2; i <= N; i++){
    // デフォルトで1文字増える
    dp[i] = dp[i-1] + 1;
    // 文字が一致した時に置換してDP配列を更新する
    if(c[i-1] == l1 && c[i-2] == l2) dp[i] = min(dp[i], dp[i-2] + 1);
    if(c[i-1] == r1 && c[i-2] == r2) dp[i] = min(dp[i], dp[i-2] + 1);
  }
  return dp[N];
}

int main(){
  int N;
  char ch;
  cin >> N;
  // 入力を受け取って数字に変換
  for(int i = 0; i < N; i++){
    cin >> ch;
    if(ch == 'A') c[i] = 0;
    if(ch == 'B') c[i] = 1;
    if(ch == 'X') c[i] = 2;
    if(ch == 'Y') c[i] = 3;
  }
  int res = 2000;
  // lの1文字目、2文字目、rの1文字目、2文字目を全て試す
  // 4^4=256
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      for(int k = 0; k < 4; k++){
        for(int l = 0; l < 4; l++){
          res = min(res, calc(N, i, j, k, l));
        }
      }
    }
  }
  cout << res << endl;
  return 0;
}