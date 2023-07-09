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
const ll INF = ll(1e18);

ll N, M;
void input() {
  cin >> N >> M;
}
void solve() {
  // M<0の時高橋君のプログラムは最適解を出力するのでこの様なことは起こり得ない
  // M=Nのとき青木君のプログラムが出力する値は必ず1以上となるのでこの様なことは起こり得ない
  // M=N-1かつN>=2の時、M=N-1になるためには高橋君のプログラムがNとなり、
  // 青木君のプログラムが出力する値が1になる必要がある
  // しかし高橋君のプログラムが出力する値がNとなる様な入力は全ての区間が交わらないので、
  // 青木君のプログラムが出力する値もNとなる、N>=2の時この様なことは起こり得ない
  if(M < 0 or M == N or (N != 1 and M == N - 1)) {
    cout << -1 << endl;
    return;
  }
  cout << "1 10000000" << endl;
  ll rest = N - 1;
  // 大きな区間の中にM+1個の区間を互いに交わらないように配置する
  // これによってこの区間で青木君が1つとる時に、高橋君はM+1個取ることができ
  // 差をMにすることができる
  if(M != 0) {
    for(int i = 1; i <= M + 1; i++) {
      cout << 2 * i << " " << 2 * i + 1 << endl;
      rest--;
    }
  }
  // 10000000をbaseにして始める
  const ll base = 1e8;
  // rest分の区間を互いが交わらないように配置する
  for(int i = 1; i <= rest; i++) {
      cout << base + 2 * i << " " << base + 2 * i + 1 << endl;
  }
  return;
}

int main() {
  input();
  solve();
  return 0;
}