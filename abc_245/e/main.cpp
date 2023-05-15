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

struct P{
    ll x,y;
    ll c;
};
signed main(){
  ll n,m;
  cin>>n>>m;
  vector<P> v(n+m);
  // まとめて入れていく
  // チョコの時はc=1, 箱の時はc=0
  rep3(i,0,n)cin>>v[i].x;
  rep3(i,0,n){cin>>v[i].y;v[i].c=1;}
  rep3(i,0,m)cin>>v[i+n].x;
  rep3(i,0,m){cin>>v[i+n].y;v[i+n].c=0;}
  // 横の長さで降順ソート(降順ソートは先に来る方が大きいか)、ただしチョコと箱が同じ大きさの時は箱が前
  sort(all(v),[](P a,P b){
    if(a.y==b.y){
      return a.c<b.c;
    }
    return a.y>b.y;
  });
  multiset<ll>S;
  // この時O((N+M)log(N+M)))となり高速に計算できる
  // 既に横の長さで降順ソート(箱とチョコが同じ大きさの時は箱が前)しているので、
  // この時点で箱の横の長さが大きい順に並んでいる
  // よってそれを見ていき、箱の時はSに縦の長さを追加、チョコの時はSからAi(縦の長さ)以上のもののうち最小のものを削除
  // 削除するものがなければNo
  // とすることで実現可能かを高速に判定することができる
  // 縦の長さを入れていく時点で横の長さは実現可能なことが確定しているので、
  // 高速に判定できる
  for(auto x:v){
    // チョコを見ている時Sの要素でAi(縦の長さ)以上のもののうち最小のものを削除、削除するものがなければNo
    if(x.c==1){
      auto itr = S.lower_bound(x.x);
      if(itr==S.end()){
        cout<<"No"<<endl;
        return 0;
      }
      S.erase(itr);
    }else{
      // 箱の時はCi(縦の長さ)を追加
      S.insert(x.x);
    }
  }
  cout<<"Yes"<<endl;
  return 0;
}