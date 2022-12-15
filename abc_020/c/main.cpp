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

using namespace std;
typedef pair<ll, pii> P;
char grid[10][11];
ll dist[10][11];
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};

int main() {
  int H,W,T;
  scanf("%d %d %d",&H,&W,&T);
  int sx,sy;
  for(int i=0;i<H;i++) {
    scanf("%s",grid[i]);
    // スタートを記録
    for(int j=0;j<W;j++) if(grid[i][j]=='S') sx=j,sy=i;
  }
  // コストを決め打ちして二分探索
  int l=1,r=1000000001;
  // 差が1になるまで見つける
  while(r-l>1) {
    int m=(l+r)/2;
    // 昇順にしてコストが小さいものから取り出している
    priority_queue<P, vector<P>, greater<P>> Q;
    // スタートから始めて最初のコストは0
    Q.push(P(0, pii(sx,sy)));
    // 初期化
    rep(i, H) rep(j, W) dist[i][j] = 1e18;
    // スタートのコストを0に
    dist[sy][sx]=0;
    ll res=0;
    // 幅優先探索だが、コストが異なるので
    // コストが小さいものから取り出すようにする
    // ダイクストラを迷路でやっている感じに近い
    while(!Q.empty()) {
      // コストが小さいものを取り出す
      P p = Q.top();
      Q.pop();
      // 座標を取り出す
      int x=p.second.first,y=p.second.second;
      // 今の座標までの距離が、現時点での最短距離より長ければ探索を打ち切る
      if(dist[y][x] < p.first) continue;
      // ゴールなら今のコストを保存して抜ける
      if(grid[y][x]=='G') {res=dist[y][x];break;}
      // 4方向
      for(int i=0;i<4;i++) {
        int nx=x+dx[i],ny=y+dy[i];
        if(0>nx||nx>=W||0>ny||ny>=H) continue;
        // コストを計算する
        long long int cost=p.first+(grid[ny][nx]=='#'?m:1);
        // 次のコストより計算したコストが低ければ
        // コスト更新して次の探索対象に加える
        if(cost<dist[ny][nx]) {
          dist[ny][nx]=cost;
          Q.push(P(cost, pii(nx,ny)));
        }
      }
    }
    // ゴールまで辿り着いた時のコストがT以下であるギリギリのラインを見つける
    if(res<=T) l=m; else r=m;
  }
  printf("%d\n",l);
}