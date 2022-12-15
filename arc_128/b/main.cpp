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

int ans[2010];
int dx[4] = { 0, 1, 0, -1 }, dy[4] = { -1, 0, 1, 0 };

const ll inf = 1e18;
ll a[3],T;
int main() {
  // 何らかの操作を行なって2つの色のボールの数が同じにする必要がある
  // 2つのボールの差が3でそれ以外のボールが1つ以上残っていれば、上記の結果になる
  // 1回の操作で変更前のボールと変更後のボールは差が3つ縮む
  // ボールとボールの差が3の倍数で、同じになるまで操作を行うための
  // 十分なボールがある時に操作を行うことができる
  // ボールの個数の差を3で割ったあまりはどの操作を行なっても変化しないことに注目する
  scanf("%d",&T);
  while(T--){
    scanf("%d %d %d",&a[0],&a[1],&a[2]);
    // ソートしても解は変わらず、シンプルに考えることができる
    // 組み合わせの問題ではソートすることで、条件分岐をなくすことができる場合がある
    sort(a,a+3);
    ll ans=inf;
    // 2つのボールの色が同じなら、そのボールの回数だけ操作を行えばよい
    if(a[0]==a[1]) ans=min(ans,a[0]);
    if(a[1]==a[2]) ans=min(ans,a[1]);
    // 2つのボールの差が3の倍数であれば、つまりG≡B mod3のような状況であれば解は存在する
    // 小さい方のボールの回数分、最終的に変更するのボールの色に変えて
    // そのあと残った分に関しては、最終的に変更する色と残った色のボールを
    // 0になったボールの色に変更してから2回、最終的に変更するボールの色に変更する操作を行う
    // このような操作の方法が最小回数を達成する操作方法であり、
    // 操作回数の合計は小さい方のボールの個数を仮にB、大きい方をGとすると、
    // B+((G-B)/3 * 3)となり、これを簡単にするとG回ということになる
    if((a[1]-a[0])%3==0) ans=min(ans,a[1]);
    if((a[2]-a[0])%3==0) ans=min(ans,a[2]);
    if((a[2]-a[1])%3==0) ans=min(ans,a[2]);
    printf("%d\n",(ans==inf)?-1:ans);
  }

  return 0;
}