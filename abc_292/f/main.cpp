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


int main() {
  int A, B;
  cin>>A>>B;
  long double L=0,R=5000;
  // 二分探索
  for(int t=0;t<100;t++)
  {
    // 平均値をとる
    // 正三角形の1辺をrにできるかどうかで二分探索
    long double r=(L+R)/2;
    long double theta;
    // rがB以下の時はtheta=0
    // この時はBに辺を合わせることができる
    if(r<=B)theta=0;
    // この時はrがBより大きくB/rは1より小さい
    // 斜辺と底辺の比からθを求める
    // r/B=cosθなのでθ=acos(r/B)
    else theta=acos(B/r);
    // もしもθが30度以下で、r*cos(30-θ)がA以下ならrが正三角形の1辺にできる
    // 正三角形の角は60度なのでθが30度以下になる
    // ここでθはBと正三角形の辺がなす角
    // M_PI/6-thetaはAと正三角形の辺がなす角
    // よって正三角形の辺の長さにcos(M_PI/6-theta)をかけると、縦の長さが得られる
    // これはA以下である必要がある
    // この時にrの長さの2辺が60度の角をなすので正三角形を作ることができる
    if(theta<=M_PI/6 && r*cos(M_PI/6-theta)<=A)L=r;
    // そうでないならrが正三角形の1辺にできない
    else R=r;
  }
  cout<<fixed<<setprecision(16)<<L<<endl;
}