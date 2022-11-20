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

long long ans[300005];

int op[300005],a[300005],cc[300005];
int n,m,c,q;
set<int> vx,vy;

int main(){
  cin>>n>>m>>c>>q;
  for(int i=1;i<=q;i++){
    cin>>op[i]>>a[i]>>cc[i];
  }
  // 逆からクエリを見ていく
  for(int i=q;i;i--){
    // 行を塗る
    if(op[i]==1){
      // 既に該当行が塗られていなければ、
      // 現在の列数を答えの配列の色のインデックスに追加(この時該当行が塗られていれば後から上書きされてしまうので操作しない)
      // 行数をデクリメントすることでその前に塗られるマス目の行数は1少なくなる(この色で上書きされるから)
      if(!vx.count(a[i])){
        vx.insert(a[i]);
        ans[cc[i]] += m;
        n--;
      }
    } else{
      // 列を塗る
      // 既に該当列が塗られていなければ、
      // 現在の行数を答えの配列の色のインデックスに追加(この時該当列が塗られていれば後から上書きされてしまうので操作しない)
      // 列数をデクリメントすることでその前に塗られるマス目の列数を少なくなる(この色で上書きされる)
      if(!vy.count(a[i])){
        vy.insert(a[i]);
        ans[cc[i]]+=n;
        m--;
      }
    }
  }
  // 色ごとにマス目の数を出力
  for(int i=1;i<=c;i++){
    cout<<ans[i]<<' ';
  }
  cout << endl;
  return 0;
}