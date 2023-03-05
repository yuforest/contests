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
const ll INF = ll(1e18);

int main() {
  string c;
  cin>>c;
  int n=c.size();
  // 大きな値で初期化
  int ans=99;
  // nまでの状態数を全探索、O(N^2*2^N) = 100*1024
  // これはテレビをつけるタイミングを表しており、フラグが全部立っていたら
  // 全ての時間で新しいテレビをつけるということになる
  for(int i=0;i<(1<<n);i++){
    bool check=true;
    // jは時間を表しており、この全てでどこかのテレビを見れる必要がある
    for(int j=0;j<n;j++){
      bool found=false;
      // nまで順番に見ていく
      // テレビをつけるタイミングを順番に見ていきどこかのテレビではjの時間に見れる必要がある
      for(int k=0;k<n;k++){
        // iという状態数はk番目のbitが立っているかどうか
        // ここでテレビをつける
        if(i>>k&1){
          // jからk進んだところ(nを超えたらmodを取って始点に戻る)がoになっているかどうか
          // kのタイミングでテレビをつけてからj進んだ時間では
          // どこかのテレビがついている必要がある
          if(c[(j+k)%n]=='o'){
            found=true;
          }
        }
      }
      if(!found)check=false;
    }
    if(check){
      // iのbitが立っている数を数えて最小値更新
      // フラグが立っている数がテレビの数であり、テレビをつけるタイミング
      ans=min(ans, __builtin_popcount(i));
    }
  }
  cout<<ans<<endl;
  return 0;
}