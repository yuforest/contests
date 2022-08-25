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

vector<int> honests[15];
vector<int> liars[15];
int main() {
  int N;
  cin >> N;
  rep(i, N) {
    int A;
    cin >> A;
    rep(j, A) {
      int x, y; cin >> x >> y;
      // 証言したごとに嘘つきの人と正直者に振り分ける
      if (y == 0) liars[i].push_back(x - 1);
      else honests[i].push_back(x - 1);
    }
  }

  int ans = 0;
  // N人をbit全探索
  rep(msk, 1 << N) {
    // 矛盾するかどうか
    bool ok = true;
    int tot = 0;
    // フラグが立った人を正直者と判断してその人の証言に矛盾がないかを調べる
    rep(i, N) if (msk & (1 << i)) {
      tot++;
      // 正直者と言われた人が今回嘘つきになっていれば矛盾
      fore(honest, honests[i]) if (!(msk & (1 << honest))) ok = false;
      // 嘘つきと言われた人が今回正直者になっている場合は矛盾
      fore(liar, liars[i]) if (msk & (1 << liar)) ok = false;
    }
    if (ok) chmax(ans, tot);
  }
  cout << ans << endl;

  return 0;
}