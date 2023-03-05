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

// ワーシャルフロイド法
// int main(void) {
//   int n;
//   long long a[300];
//   string s;
//   int d[300][300];
//   long long val[300][300];

//   cin >> n;
//   for(int i=0;i<n;i++) cin>>a[i];

//   // グラフを初期化
//   for(int i=0;i<n;i++)for(int j=0;j<n;j++)d[i][j]=n,val[i][j]=0;
//   // 同じ点への距離と価値の総和は0
//   for(int i=0;i<n;i++) d[i][i]=0,val[i][i]=0;
//   // グラフの構築
//   for(int i=0;i<n;i++) {
//     cin >> s;
//     for(int j=0;j<n;j++){
//       // コスト1で到達可能、jに到達した時にa[j]の価値を得る
//       if(s[j]=='Y')d[i][j]=1, val[i][j]=a[j];
//     }
//   }

//   // jを経由してiからkに向かうコストを計算する
//   for(int j=0;j<n;j++){
//     for(int i=0;i<n;i++){
//       for(int k=0;k<n;k++){
//         // 最短経路を更新できるとき
//         if((d[i][j]+d[j][k])<d[i][k]){
//           d[i][k]=d[i][j]+d[j][k];
//           val[i][k]=val[i][j]+val[j][k];
//         }
//         // もしくは最短経路と同じで今の価値の合計より大きい時、価値の合計を更新する
//         else if(((d[i][j]+d[j][k])==d[i][k])&&((val[i][j]+val[j][k])>val[i][k])){
//           val[i][k]=val[i][j]+val[j][k];
//         }
//       }
//     }
//   }

//   int q,u,v;
//   cin >> q;
//   for(int i=0;i<q;i++){
//     cin >> u >> v;
//     // 経路数がn以上になることはない、そのような時は実現不可能
//     if(d[u-1][v-1]==n)cout<<"Impossible\n";
//     // 出発地点のお土産と出発地点からゴールまで行った時の価値の合計を足したものが答え
//     else cout<<d[u-1][v-1]<<" "<<(val[u-1][v-1]+a[u-1])<<"\n";
//   }
//   return 0;
// }


signed main() {

  ll n;
  cin >> n;
  ll INF = n;

  long long a[300];
  string s[300];
  ll dist[300][300];
  long long ans[300][300];
  for(int i=0;i<n;i++)for(int j=0;j<n;j++) dist[i][j]=n, ans[i][j]=0;

  for(int i=0;i<n;i++)cin>>a[i];
  for(int i=0;i<n;i++)cin>>s[i];
  rep(i,n){
    dist[i][i] = 0;
    // 出発地の空港で買うお土産
    ans[i][i] = a[i];
    queue<int> Q;
    Q.push(i);
    while(Q.size()){
      auto u = Q.front();Q.pop();
      rep(v,n)if(s[u][v]=='Y'){
        // 最小値更新したら探索を続ける
        if(chmin(dist[i][v],dist[i][u]+1))Q.push(v);
        // 次までの距離が今までの距離+1なら、価値の最大値更新も行う
        if(dist[i][v]==dist[i][u]+1) chmax(ans[i][v], ans[i][u]+a[v]);
      }
    }
  }
  int q;
  cin >> q;
  while(q--){
    ll u,v;
    cin >> u >> v;
    --u;--v;
    if(dist[u][v]==INF){
        cout << "Impossible" << endl;
    }
    else{
      cout << dist[u][v] << " " << ans[u][v] << endl;
    }
  }
  return 0;
}
