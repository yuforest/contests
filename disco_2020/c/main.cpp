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

int ans[2010];

vector<pair<int, int>> directions = {{0, 1}, {1, 0}};

int main() {
  int H, W, K;
  cin >> H >> W >> K;
  int A[H][W];
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      char c;
      cin >> c;
      if(c=='.') A[i][j]=-1;
      else{
        // いちごのある場所を記録
        A[i][j] = K;
        K--;
      }
    }
  }
  // 2番目の列から始めて、左から右に動きながら、現在の場所が-1なら左の数を採用
  for(int i=0;i<H;i++){
    for(int j=1;j < W;j++){
      if(A[i][j] == -1) A[i][j] = A[i][j-1];
    }
  }
  // 最後から2番目の列から始めて、右から左に動きながら、現在の場所が-1なら右の数を採用
  for(int i=0;i<H;i++){
    for(int j=W-2;j>=0;j--){
      if(A[i][j]==-1) A[i][j] = A[i][j+1];
    }
  }
  // 2行目から始めて、上から下に動きながら、現在の場所が-1なら上の数を採用
  for(int i=1;i<H;i++){
    for(int j=0;j<W;j++){
      if(A[i][j]==-1) A[i][j] = A[i-1][j];
    }
  }
  // 最後から2行目から始めて、下から上に動きながら、現在の場所が-1なら下の数を採用
  for(int i=H-2;i>=0;i--){
    for(int j=0;j<W;j++){
      if(A[i][j]==-1) A[i][j] = A[i+1][j];
    }
  }

  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      printf("%d ",A[i][j]);
    }
    printf("\n");
  }
  return 0;
}