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
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep3(i,a,b) for(ll i=a;i<b;i++)
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
ll gcd(ll x, ll y) { return (x % y)? gcd(y, x % y): y; }


const int inf=INT_MAX/2-100;
int main() {
  int n,k;
  cin>>n>>k;
  vpii a;
  rep(i,n) {
    int val;
    cin >> val;
    // 数字が同じなら大きいインデックスから探索したいので
    // -1を掛けている
    // 例えば
    // 4 2
    // 2 1 1 2
    // のように値が同じでそれらが境界にある場合
    // [ (1, -2) (1, -1) (2, -3) (2, 0) ]
    // ではなく
    // [ (1, 1) (1, 2) (2, 3) (2, 0) ]
    // のようになり、
    // 答えに1がセットされてしまう
    // しかしこのとき値が同じなので
    // 条件を達成しない
    // よって値が同じなら、大きなインデックスから探索する必要がある
    // そうすればKより大きな値のインデックスがきた後に
    // K以下のインデックスの最大値が更新されるので
    // 同じ数字の時に答えになることがない
    a.push_back({val, -i});
  }
  // (Ai, -i)の昇順に並べて見ていく
  sort(all(a));
  debug(a);
  int mx=-inf,ans=inf;
  for(auto [v,i]: a){
    i=-i;
    // 今見ているiがK+1<=iならば、
    // 今まで見たiのうちi<=Kであるものの中で最大であるものをjとして
    // Aj<Aiの入れ替えが最適解の候補として挙がる
    // このときこの値は先頭からK番目以内にある
    // つまりここでは交換できる小さい値のインデックスを更新している
    // これ以降に出てくる値は全て現在の値より大きいことが保証される
    // このインデックスはK番目に近ければ近いほど良い
    // よって最大値を更新する
    if(i<k) chmax(mx,i);
    // このときこの値はK+1番目からN番目までにあることを示す
    // このときmxの値が更新されていなければi-mxはansより大きくなり
    // 答えは更新されない
    else {
      debug(ans);
      debug(i-mx);
      chmin(ans, i-mx);
    }
  }
  // ansが一度も変わらなければ−1
  if(ans >= inf) ans=-1;
  cout << ans << endl;
}