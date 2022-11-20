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

const int max_n = 100005;
const int max_m = 100005;
int n,m;
int p[max_m];
long long a,b,c;
long long sum[max_m], ans;

int main() {
  cin >> n >> m;
  rep3(i,1, m+1) cin >> p[i];
  // いもす法で乗った箇所をインクリメント、降りた箇所をデクリメントする(逆向きでも料金は同じなので操作を逆にする)
  rep3(i,1, m) {
    // 大きい数字の方向に鉄道を利用する場合
    if (p[i] < p[i+1]) {
      sum[p[i]]++;
      sum[p[i+1]]--;
    } else {
      // 逆向きに鉄道を利用する場合
      sum[p[i]]--;
      sum[p[i+1]]++;
    }
  }
  // debug(sum);
  // 鉄道はN-1個なのでその数だけ繰り返す
  rep3(i, 1, n) {
    // いもす法の累積和を計算
    // 各区間の鉄道に合計何回乗ったかという情報がわかる
    sum[i] += sum[i-1];
    cin >> a >> b >> c;
    // ICカードの初期費用も含めてどちらがお得かを区間ごとに計算
    ans += min(a * sum[i], b * sum[i] + c);
  }
  // debug(sum);
  cout << ans << "\n";
  return 0;
}