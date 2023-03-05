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
#define per3(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) per3(i, 0, b)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(), (x).end()

// 無くても困らない
#define INFTY (1 << 30)

// 浮動小数点の誤差を考慮した等式ですが、使わずに済むなら使わない方が確実です
#define EPS (1e-7)#define equal(a, b) (fabs((a) - (b)) < EPS)

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

int N,M,Q;
bool ans[2<<17];
int main() {
  cin>>N>>M>>Q;
  vector<pair<pair<int,int>,pair<int,int> > >E;
  E.reserve(M+Q);
  // 元の辺もクエリも全て辺として追加してしまう
  for(int i=0;i<M;i++) {
    int a,b,c;cin>>a>>b>>c;
    E.push_back(make_pair(make_pair(c,-1),make_pair(a,b)));
  }
  for(int i=0;i<Q;i++) {
    int a,b,c;cin>>a>>b>>c;
    // コストとクエリの番号をセットにしたpairを作る
    E.push_back(make_pair(make_pair(c,i),make_pair(a,b)));
  }
  // +1しているので1-indexedでOK
  dsu uf(N+1);
  sort(E.begin(),E.end());
  for(int i=0;i<E.size();i++) {
    int u=E[i].second.first,v=E[i].second.second;
    if(!uf.same(u,v)) {
      // -1の時はマージする、そうでない時は答えtrueにする
      // もしこれがあれば最小全域木の辺として追加されていたということ
      // (ここでは後の状態に影響を与えないので追加しない)
      if(E[i].first.second==-1)uf.merge(u,v);
      else ans[E[i].first.second]=true;
    }
  }
  for(int i=0;i<Q;i++) cout<<(ans[i]?"Yes\n":"No\n");
}