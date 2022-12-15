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


int h,w;
int a[1252][1252];
ll dp[1252][1252];
// 4方向を探索するための配列、インデックスを0~3まで動かしてi,i+1を見ていけば良い
int d[] = {1,0,-1,0,1};

// メモ化再帰
ll dfs(ll y,ll x){
  // -1でなければ答えが既に入っているので結果を返す
  if(dp[y][x]!=-1)return dp[y][x];
  // 現在のマスだけの経路で1通り
  ll cur = 1;
  // 4方向を深さ優先探索で再帰的に探索
  rep(i,4){
    // 0の時ny=y+1,nx=x,下
    // 1の時ny=y,nx=x-1,左
    // 2の時ny=y-1,nx=x,上
    // 3の時ny=y,nx=x+1,右となる
    int ny = y+d[i], nx = x+d[i+1];
    // nx,nyがグリッドの範囲外であれば探索しない
    if(ny<0 || nx<0 || ny>=h || nx>=w)continue;
    // 次が現在の値よりも大きくなければ探索しない
    if(a[y][x]>=a[ny][nx])continue;
    cur += dfs(ny,nx);
  }
  // 答えを保存しつつ、返す
  return dp[y][x] = cur%mod;
}

int main(){
  scanf("%d%d",&h,&w);
  // 入力を受け取る
  rep(i,h)rep(j,w)scanf("%d",&(a[i][j]));
  // -1で初期化
  rep(i,h)rep(j,w)dp[i][j] = -1;
  ll ans = 0;
  // 全てのマスの経路数を最終的な答えに足してmodを取る
  rep(i,h) rep(j,w){
    ans += dfs(i,j);
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}