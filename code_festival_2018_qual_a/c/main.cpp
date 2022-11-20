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


int main() {
  int h,w;
  int a[28]={};
  cin>>h>>w;
  char chr;
  for(int i=0;i<h*w;i++){
    cin>>chr;
    int k=chr-97;
    a[k]++;
  }
  int t4=0;
  int t2=0;
  int t1=0;
  for(int i=0;i<28;++i){
    // 文字ごとにグループに分割している
    t4+=a[i]/4;
    t2+=a[i]/2;
    t1+=a[i]%2;
  }
  bool flg=true;
  // 2*2以上のマスがあり、4つある文字は(h/2)*(w/2)グループだけ存在する
  if((h/2)*(w/2)>0&&t4!=(h/2)*(w/2))flg=false;
  // 2つある文字は(w*h)/2グループだけ存在する
  if(t2!=((w*h)/2))flg=false;
  // 1つしかない文字はwとhが奇数の時に1つだけ存在可能
  if(t1!=(w%2)*(h%2))flg=false;
  if(flg){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
  return 0;
}
// 各 i (1 ≤ i ≤ H), j (1 ≤ j ≤ W) に対して
// a[i][j] = a[i][W+1-j] = a[H+1-i][j] = a[H+1-i][W+1-j]
// 行列の要素はサイズ 1, 2, 4 のグループへ分割される