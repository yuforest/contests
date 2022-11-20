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

ll n,d,x,p[10][10],dp[1<<17];
int main(void){
  // 入力
  int m;
  cin>>m;
  vector<pair<int,int>> star(m);
  for(int i=0;i<m;i++){
    cin>>star[i].first>>star[i].second;
  }
  int n;
  cin>>n;
  vector<pair<int,int>> sky(n);
  for(int i=0;i<n;i++){
    cin>>sky[i].first>>sky[i].second;
  }
  // skyを全探索
  // N^2 * M
  for(int i=0;i<n;i++){
    // そこに星座の0番目を並行移動させている
    int x = sky[i].first - star[0].first;
    int y = sky[i].second - star[0].second;
    // 星座の星の数で初期化
    vector<bool> tf(m,false);
    bool ok = true;
    // 星座を1から全探索
    for(int j=1;j<m;j++){
      for(int k=0;k<n;k++){
        // 星を並行移動させた上で一致するものがあれば、trueを入れている
        if(sky[k].first==star[j].first+x && sky[k].second==star[j].second+y){
          tf[j] = true;
          break;
        }
      }
      if (tf[j] == false) {
        ok = false;
      }
    }
    if (ok) {
      cout << x << " " << y <<endl;
      break;
    }
  }
  return 0;
}