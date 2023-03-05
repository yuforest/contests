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

int main(void){
 const int inf = 100000000;

  int n,m;
  cin >> n >> m;

  int a[1000],b[1000],c[1000],dist[100][100];

  for(int i = 0; i < m; ++i){
    cin >> a[i] >> b[i] >> c[i];
    // 0-indexedにする
    a[i]--,b[i]--;
  }

  // 初期値を設定する
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      if(i==j) dist[i][j]=0;
      else dist[i][j]=inf;
    }
  }

  // 最初の距離を設定する
  for(int i = 0; i < m; ++i){
    dist[a[i]][b[i]]=min(dist[a[i]][b[i]],c[i]);
    dist[b[i]][a[i]]=min(dist[b[i]][a[i]],c[i]);
  }

  // ワーシャルフロイド法
  // 全頂点間の最短距離を求める
  for(int k = 0; k < n; ++k){
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < n; ++j){
        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
      }
    }
  }

  // 初期値は全ての辺
  int ans=m;
  // 辺を全探索
  for(int i = 0; i < m; ++i){
    bool shortest=false;
    // 辺ごとに頂点を全探索、これは始点となる
    // jからa[i]に行く距離+辺の重さがjからb[i]に行く距離と等しいかどうかを調べる
    // 等しければこの辺は最短距離に含まれることになる
    for(int j = 0; j < n; ++j) if(dist[j][a[i]]+c[i]==dist[j][b[i]]) shortest=true;
    // 含まれていた場合はansを1減らす
    if(shortest==true){
      ans=ans-1;
    }
  }

  cout << ans << endl;
}