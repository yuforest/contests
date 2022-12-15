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

using mint = modint998244353;
int main() {
  // 解の最大ケースは2^N-1通り(空の部分集合を除く)
  // iとf(i)が一致しているもの同士ではそれを選ぶか選ばないかで通り数を作ることができる
  // 例えばその数をAとすると2^A-1通りの数を作ることができる
  // そうでない数同士でも互いに解が循環している組み合わせであればカウントする
  // つまりi=1,2,3に対してそれぞれf(i)=3,2,1のようなものは1つとしてカウントできる
  // 循環の組み合わせがある時その部分集合内で他に組み合わせができることはない
  // ただしiとf(i)が一致しているものであれば組み合わせて解を作ることができるので
  // その組み合わせ分増える(この時は空集合も含んで良い)
  // この問題をグラフ的に考えると入次数と出次数がそれぞれ1のN個の頂点(iとf(i)が同じものは自己ループ)
  // において閉路のある個々の連結成分の組み合わせは何通り作れるかという問題になる
  // UnionFindで単に連結して、リーダーが自分自身の頂点数を数えても良い
  int N;
  cin>>N;

  dsu D(N);
  rep(i,N){
    int u;
    cin>>u;
    u--;
    D.merge(i,u);
  }

  int cnt =0;
  rep(i,N){
    if(D.leader(i)==i)cnt++;
  }
  debug(cnt);

  mint ans = mint(2).pow(cnt);
  ans--;

  cout<<ans.val()<<endl;

  return 0;
}
