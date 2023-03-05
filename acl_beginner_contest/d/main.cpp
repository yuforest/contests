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

//op : segment tree の2要素に対する演算
//sのl番目からr番目までの区間に対する求めたいものは op(s_l,op(s_{l+1},...,s_r)) にあたる
//今回は max(s_l,max(s_{l+1},...,s_r)) にあたるので op は max にあたるものを書く
int op(int a,int b){
  return max(a,b);
}

//e : 単位元
//op(a,e) = aとなる
// 操作を行なった時に同じ値が返ってくるようになる値を返す
int e(){
  return 0;
}

int main(){
  int n,k;
  cin>>n>>k;

  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }

  //300001要素のsegtree(Range Max Query)を作る
  //seg[i]でiが末尾のBで長さが最長のものの長さ
  segtree<int,op,e> seg(300001);

  for(int x:a){
    //区間の左端,右端がl,r(負になったり300001より大きくなったりしないようにmaxやminで調整)
    // 半開区間[l, r)となるように設定する
    int l=max(x-k,0),r=min(x+k+1,300001);

    //prodで区間に対する最大値を取得
    //prod(a,b)でa番目から"b-1"番目までなので注意(b番目は含まない)
    // xとの差がkとなる値の最大値を取得
    int mx = seg.prod(l,r);
    debug(mx);

    //seg[x]の更新
    // 今の値を最大値+1に更新
    // xを繋げられる部分列の最大値はmx個なので、
    // xを繋ぐことでxまででmx+1個の部分列を作ることができる
    seg.set(x,mx+1);
  }

  //全要素の最大値を取得
  int ans = seg.all_prod();
  cout<<ans<<endl;
}