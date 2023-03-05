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

// xをiだけ右シフト
#define bit(x,i)(((x)>>(i))&1)

// 操作はbitごとに独立である
// 繰り上がったりすることがない
// その特定bit内で完結する操作ということ
int main(){
  int n, c;
  cin >> n >> c;
  // 操作を記録
  vector<pair<int,int>> op(n);
  for(int i=0;i<n;i++) cin >> op[i].first >> op[i].second;
  // 答えは最初全て0
  vector<int> ans(n);
  // ビット毎に計算する
  for(int k=0;k<30;k++){
    // 型と長さ
    // 元のbitが0だった場合と1だった場合を示している
    array<int, 2> func = {0,1};
    // cのk桁目のbitが立っていたら1、そうでなければ0
    int crr = bit(c,k);
    // 操作を全探索
    // kbit目に対して各操作を行った時にどうなるか
    // curは前回の操作によって変化するので、
    // 例えばi=1はi=0の操作を行なった後に、操作したらどうなるかという結果となっている
    // 同様にi=5にはiが0から4の時の結果が反映されている
    // よってans[i]にorを取ることで、そのbitについての答えを足すことができる
    for(int i=0;i<n;i++){
      array<int,2>f;
      // 操作の対象となる数のbitを取得
      int x = bit(op[i].second, k);

      // and
      if(op[i].first==1)f={0&x,1&x};
      // or
      if(op[i].first==2)f={0|x,1|x};
      // xor
      if(op[i].first==3)f={0^x,1^x};
      // 操作の種類に従って、結果を計算したものをfuncに代入する
      func = {f[func[0]], f[func[1]]};
      // 今の値を入れた時の結果をcurに入れる、計算結果
      crr = func[crr];
      debug(ans[i]);
      // crrをkだけ左シフトしたものと答えのorを取る
      ans[i] |= crr<<k;
    }
  }
  for(int i=0;i<n;i++) {
    cout << ans[i] << endl;
  }
}