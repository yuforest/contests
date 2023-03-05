// 標準ライブラリを全て読み込む
// 本書では細かく書きませんが、下記リンクが参考になります
// https://atcoder.jp/contests/apg4b/tasks/APG4b_af
#include <bits/stdc++.h>
// stdのstd::cinのような書き方ではなくcinと書けば良くなる
using namespace std;

// デバッグ用マクロ
// 本書では細かく書きませんが、下記リンクが参考になります
// https://naskya.net/post/0002/
#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

// データ構造の省略
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

// modの計算
long long mod1 = 1000000007;
long long mod2 = 998244353;

// 隣接グラフ(1 << 18は2^18で262144となる)
// vector<ll> G[1 << 18];

// ACL(AtCoder Library)、普段はコメントアウトしてある
// #include <atcoder/all>
// using namespace atcoder;

// repマクロ
// 0からn-1まで
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// aからb−1まで
#define rep3(i,a,b) for(int i=a;i<b;i++)
// n-1から0まで
#define per(i, n) for (int i = int(n) - 1; i >= int(0); i--)
// b-1からaまで
#define per3(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
// 範囲for文の省略
#define fore(i,a) for(auto &i:a)
// sort(A.begin(), A.end())をsort(all(A))のように書けます
#define all(x) (x).begin(), (x).end()

// 最大値と最小値の更新
// 返り値は更新した場合はtrue、そうでなければfalse
template <typename T>
inline bool chmax(T &a, T b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T>
inline bool chmin(T &a, T b) {
  return ((a > b) ? (a = b, true) : (false));
}

int N,M;
vector<int>G[2000];
int dp[2000][2000];
int C[2000];
int main() {
  int T;cin>>T;
  for(;T--;)
  {
    cin>>N>>M;
    for(int i=0;i<N;i++)
    {
      cin>>C[i];
      // 初期化
      G[i].clear();
      for(int j=0;j<N;j++)dp[i][j]=1e9;
    }
    for(int i=0;i<M;i++)
    {
      int u,v;cin>>u>>v;
      u--,v--;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    // 高橋が0にいて青木がN-1にいる時は0回移動している
    dp[0][N-1]=0;
    queue<pair<int,int> >Q;
    Q.push(make_pair(0,N-1));
    // 高橋がuにいて青木がvにいる時の最小移動回数をdp[u][v]とする
    // 幅優先探索的なことをする
    while(!Q.empty())
    {
      int u=Q.front().first,v=Q.front().second;
      Q.pop();
      // 組み合わせの中で色が異なり、かつ、移動回数が更新できる時は更新してキューに追加する
      for(int uu:G[u])for(int vv:G[v]) if(C[uu]!=C[vv]&&dp[uu][vv]>dp[u][v]+1)
      {
        // 距離を更新
        dp[uu][vv]=dp[u][v]+1;
        // キューに追加
        Q.push(make_pair(uu,vv));
      }
    }
    // 高橋がN-1,青木が0にいる時の最小移動回数を出力する
    int ans=dp[N-1][0];
    if(ans==(int)1e9)ans=-1;
    cout<<ans<<"\n";
  }
}