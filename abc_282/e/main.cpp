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

#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int N,M;
int A[500];
// 繰り返し二乗法
int pw(int a,int b) {
  int e=1%M;
  while(b)
  {
    if(b&1)e=(long)e*a%M;
    b>>=1;
    a=(long)a*a%M;
  }
  return e;
}

int main() {
  cin>>N>>M;
  for(int i=0;i<N;i++)cin>>A[i];
  vector<pair<int,pair<int,int> > >E;
  // N個のボールのペアに対して計算した値とi,jの組の配列を追加している
  // N+(N-1)+(N-2)+...+1となる
  for(int i=0;i<N;i++) for(int j=i+1;j<N;j++) {
    E.push_back(make_pair((pw(A[i],A[j])+pw(A[j],A[i]))%M, make_pair(i,j)));
  }
  // スコア順にソートして、降順に並べている
  sort(E.begin(),E.end());
  reverse(E.begin(),E.end());
  long ans=0;
  atcoder::dsu uf(N);
  for(pair<int,pair<int,int> >p:E) {
    // i,jの組を取得する
    int u=p.second.first,v=p.second.second;
    // これが連結成分でなければ連結してスコアを加算する
    // つまりボールの片方が既に使われていた場合はその組は使えない
    // 例えばボールが3つあって1,2の組、1,3の組を作ったとする
    // その後に2,3の組で取り出そうとしてもこれらは連結されているため取り出すことができない
    // 1,2の組、1,3の組で取り出した時には2か3のどちらかのボールは既に箱の中に存在しないためである
    // スコアが大きい順に足していくので最大値を達成することができる
    // グラフの最大全域木問題であり、閉路を作らないようにする辺を採用する時の判定にunion findを
    // 用いるクラスカル法によって解くことができる
    if(!uf.same(u,v)) {
      uf.merge(u,v);
      ans+=p.first;
    }
  }
  cout<<ans<<endl;
}