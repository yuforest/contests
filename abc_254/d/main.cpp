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

// 最大の平方数をf(N)とおく
// i*jが平方数となることはi*j/f(i)*f(j)が平方数となることと同値
// つまりi,jから平方数を取り除いた後に掛けて平方数になれば良い
// i/f(i)がある素数pで2回以上割り切れることはない
// なぜならiを素因数分解したとき素数項の指数が奇数の場合、指数の偶数部分はf(i)で割ることでなくなるので
// 残る素数は0個か1個になる
// つまりi/f(i)とj/f(j)は同じものである必要がある
// そうでないと掛けても平方数にならない
// そこでi/f(i)の数を1からNまでカウントして、
// そのカウントの2乗和を取れば答えになる
int main() {
  int n;
  cin>>n;
  vector<bool> sq(n+1,false);
  // N以下の平方数を求める
  for(int i=1;i*i<=n;i++) sq[i*i] = true;
  // 二次元配列
  vector<vector<int>> d(n+1);
  // 1からNまでの数に対して操作を行う
  // ここの計算量は調和級数的になる、O(NlogN)、N+N/2+N/3+...1
  for(int i=1;i<=n;i++){
    // iの倍数となる数の配列にiをpushしていく
    // 約数列挙をしている、d[j]にはiをpushしているので約数が昇順に並ぶことになる
    for(int j=i;j<=n;j+=i) d[j].push_back(i);
  }
  vector<int> cnt(n+1);
  for(int i=1;i<=n;i++){
    int f=0;
    // 約数を全探索
    // その約数が平方数であればfを更新
    // つまりiの約数の内最大の平方数を探索している
    for(int j=0;j<d[i].size();j++) if(sq[d[i][j]]) f=d[i][j];
    // iから平方数を取り除いた後に残る数字の数をカウントしている
    cnt[i/f]++;
  }
  int ans=0;
  for(int i=1;i<=n;i++) {
    debug(cnt[i]);
    ans+=cnt[i]*cnt[i];
  }
  cout<<ans<<endl;
}