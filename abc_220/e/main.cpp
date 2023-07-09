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

using m32 = atcoder::modint998244353;

int main(){
  int N;
  cin >> N;
  vector<m32> pow2table(N*2+1,1);
  for(int i=1; i<=N*2; i++) pow2table[i] = pow2table[i-1] * 2;
  // for(int i=0; i<=N*2; i++) debug(pow2table[i].val());


  int D;
  cin >> D;
  // 各頂点v について、「距離がD である頂点の組 (i,j)であって、
  // i,j のLCA (Lowest Common Ancestor) が vであるようなもの」の個数を考え、これを
  // f(v) とおきます。求めるものは全ての頂点についてのf(v) の合計です。
  // vの深さをd
  // v=i or v=jの時、他方の頂点はvの子孫である深さd+Dの頂点から自由に選ぶことができる
  m32 ans = 0;
  // 深さを全探索
  for(int d=0; d<=N-1; d++){
    m32 f1d;
    // dの位置からDだけ下に降りた時に、ある頂点の総数、D+1しているのは反対にした時にも同じ数だけあるため
    // 2倍する必要があるから
    if(d+D <= N-1) f1d = pow2table[D+1];
    else f1d = 0;
    // 0<k<Dで、iはvの左側にある深さd+kの頂点、jはvの右側にある深さd+(D-k)の頂点から選んだ時
    m32 f2d;
    // D=1か、ここから下に降りてもDより下に降りることができない時は0
    if(2*(N-1-d) < D || D == 1) f2d = 0;
    // それ以外でどちらに行ってもDより下に降りることができる時は、
    // 各vに対して2^(D-2)個の選び方があり、反対もあるので2倍する
    // さらに右と左の配分を調整することでD-1通りあるので掛ける
    else if(d+D <= N-1) f2d = pow2table[D-1] * (D-1);
    // どちらもがDより下に降りることができない時は、
    // (2*N-2*d-D-1)は長さを左と右で調整した時の長さの構築方法の数
    // N=3,D=2,d=1の時
    // 2(N-d)-D-1、つまり全体の深さNから今の深さdを引いて、2倍して、Dを引いて、1引いた数
    // 2(3-1)-2-1=2*2-2-1=1
    // 2*N-2*dは深さdの頂点から葉までのパスの長さ
    else f2d = pow2table[D-1] * (2*N-2*d-D-1);
    debug(d);
    debug(f1d.val());
    debug(f2d.val());
    debug(pow2table[d].val());
    // 場合1と場合2がそれぞれこの深さの頂点数分あるので
    // それぞれの場合の数を足し合わせる
    ans += pow2table[d] * (f1d + f2d);
  }

  cout << ans.val() << endl;
  return 0;
}