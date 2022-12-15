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

int n,m,s1,s2,is[1505][1505],b[1505][1505],ans=0;
int main(){
  cin>>n>>m>>s1>>s2;
  for(int i=1,x,y;i<=s1;i++){
    cin >> x >> y;
    b[x][y]=1;
  }
  for(int i=1,x,y;i<=s2;i++){
    cin >> x >> y;
    b[x][y]=2;
  }
  // 一度光源が届けばよい
  // 方向を分けて探索していく
  // 左上から右方向に探索
  // つまりこの探索では電球から左方向に伸びる光が照らす位置を調べることができる
  // O(HW)の計算量となる、ここで左に伸びる光のみに焦点を当てることで計算量を
  // 定数倍にできるという点がポイント
  for(int i=1;i<=n;i++){
    // 右に進んでいくにあたって最初のlstは0
    for(int j=1,lst=0;j<=m;j++){
      // 探索箇所がブロックだったら、lstにその横方向の位置を入れる
      if(b[i][j]==2)lst=j;
      // 電球だったらlst+1の位置から電球の位置までを照らすように変更
      if(b[i][j]==1){
        // この探索は合計して横幅であるmとなるので定数倍で済む
        // 左から右に向かって探索する
        for(int k=lst+1;k<=j;k++)is[i][k]=1;
        // 照らした後は電球の箇所を次の電球が照らす開始位置にしておく
        lst=j;
      }
    }
  }
  // 右上から左方向に探索していく
  // つまりこの探索では電球から右方向に伸びる光が照らす位置を調べることができる
  for(int i=1;i<=n;i++){
    for(int j=m,lst=m+1;j>=1;j--){
      // 探索箇所がブロックだったら、lstにその横方向の位置を入れる
      if(b[i][j]==2)lst=j;
      // 電球だったらlst+1の位置から電球の位置までを照らすように変更
      if(b[i][j]==1){
        // 右から左に向かって探索する
        for(int k=lst-1;k>=j;k--)is[i][k]=1;
        lst=j;
      }
    }
  }

  // 右上から下方向に探索していく
  // つまりこの探索では電球から上方向に伸びる光が照らす位置を調べることができる
  for(int i=1;i<=m;i++){
    for(int j=1,lst=0;j<=n;j++){
      // 探索箇所がブロックだったら、lstにその横方向の位置を入れる
      if(b[j][i]==2)lst=j;
      if(b[j][i]==1){
        // 上から下に向かって探索する
        for(int k=lst+1;k<=j;k++)is[k][i]=1;
        lst=j;
      }
    }
  }

  // 左下から上方向に探索していく
  // つまりこの探索では電球から下方向に伸びる光が照らす位置を調べることができる
  for(int i=1;i<=m;i++){
    for(int j=n,lst=n+1;j>=1;j--){
      // 探索箇所がブロックだったら、lstにその横方向の位置を入れる
      if(b[j][i]==2)lst=j;
      if(b[j][i]==1){
        // 下から上に向かって探索する
        for(int k=lst-1;k>=j;k--)is[k][i]=1;
        lst=j;
      }
    }
  }
  // 光の届く位置をカウント
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++)if(is[i][j])ans++;
  }
  cout << ans << endl;
  return 0;
}