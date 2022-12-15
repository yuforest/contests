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
int x[10010], n;

int main() {
  cin >> n;
  for(int i=0;i<n;i++) {
    char c;
    int a, b;
    // このようにして入力を受け取ることができる
    cin>>a>>c>>b;
    // a,bを分表示に直す
    a=(a/100)*60+(a%100);
    b=(b/100)*60+(b%100);
    // 5分以下の部分を切り捨て
    a=a/5*5;
    // 5分以下の部分を切り上げ
    b=(b+4)/5*5;
    // いもす法、aからbの時刻まで雨が降っていた
    x[a]++;
    x[b]--;
    debug(a);
    debug(b);
  }
  int sum=0;
  // 1日の終わりまで探索する
  for(int i=0;i<=24*60;i++){
    // 時刻表示に戻している
    int a=i/60,b=i%60;
    // 開始時刻のタイミングで時刻をプリント
    if(sum==0&&sum+x[i]>0){
      // sumが0で、sum+x[i]が0より大きくなる時その時刻に雨が降り始めた問いうこと
      printf("%02d%02d",a,b);
    }else if(sum>0&&sum+x[i]==0){
      // sumが0より大きく、sum+x[i]が0になる時、その時刻に雨が降り止んだということ
      printf("-%02d%02d\n",a,b);
    }
    sum+=x[i];
  }
  return 0;
}