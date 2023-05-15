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

// Ai >= AjかつBi <= Bjを満たす(i, j)の組は何個あるか？
// 座標圧縮
void comp(vector<int>&a){
  set<int>s(a.begin(),a.end());
  map<int,int>d;
  int cnt=0;
  for(auto x:s)d[x]=cnt++;
  // aを書き換える
  for(auto&x:a)x=d[x];
}

auto op=[](long long a,long long b){return a+b;};
auto e=[](){return 0LL;};

int main(){
  int n;
  cin >> n;
  vector<int>a(n),b(n);
  for(int i=0;i<n;i++)cin >> a[i];
  for(int i=0;i<n;i++)cin >> b[i];
  comp(a);
  comp(b);
  debug(a, b);

  vector<pair<int,int>>c(n);
  for(int i=0;i<n;i++)c[i]=make_pair(-a[i],b[i]);
  // 昇順ソート
  // Aの降順(マイナスを掛けるので)、Aが同じならBの昇順
  sort(c.begin(),c.end());
  debug(c);

  segtree<long long, op, e>seg(n);

  long long ans=0;
  // Aiで降順になっているので、これまでにみたプレゼントは必ずAi >= Ajの条件を満たす
  // iと対になって条件を満たすjの個数は、今までに見たプレゼントのうち、
  // Bi<=Bjを満たすものの個数
  // これはセグ木で管理できる
  for(int i=0;i<n;i++){
    int cnt=1;
    // i+1からnの中で、ペアが全く同じものがあるか調べて数える
    while(i+1<n&&c[i]==c[i+1])cnt++,i++;
    // Biの値を取り出す
    int b = c[i].second;
    // Bi以下の個数を数える
    // cntがj、(cnt+seg.prod(0,b+1))がiを表している
    // jは固定して、条件を満たすiの個数を数えている
    ans+=cnt*(cnt+seg.prod(0,b+1));
    debug(seg.prod(0,b+1));
    // Biの個数を更新
    seg.set(b,seg.get(b)+cnt);
  }
  cout << ans << endl;
}