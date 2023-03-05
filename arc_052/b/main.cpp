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

// 円錐の始まり、底面積の半径、高さ、基準点を受け取り円錐の体積を返す関数
double Calc(double x,double r,double h,double p){
  // 基準点が円錐の先よりも先にあれば面積は0
  if(p>=x+h)
    return 0;
  // 基準点がxより前にあれば、円錐の始まりはxからとなる
  if(p<x)
    p=x;
  // 円の半径に高さに対する比率を掛けている
  // (x+h-p)は基準点から円錐の先までの高さ、hは円錐の高さ
  // 基準点で切った円錐の半径は、元の半径に高さの比率をかけたものに等しい
  r*=(x+h-p)/h;
  // (r*r*M_PI)は底面積の半径、これに高さを掛けて3で割ると円錐の体積が求められる
  return (r*r*M_PI)*(x+h-p)/3;
}

double x[100],r[100],h[100];

int main(){
  int n, q;
  cin >> n >> q;
  rep(i,n) cin >> x[i] >> r[i] >> h[i];
  rep(_,q){
    double a, b;
    cin >> a >> b;
    double ans=0;
    rep(i,n){
      // aより先にある円錐の体積を計算して足す
      ans+=Calc(x[i],r[i],h[i],a);
      // bより先にある円錐の体積を計算して引く
      ans-=Calc(x[i],r[i],h[i],b);
    }
    printf("%.10f\n",ans);
  }
}