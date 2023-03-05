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
#define per(i, b) per2(i, 0, b)
#define per3(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
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

int main() {
 int n;
  cin >> n;
  string t;
  cin >> t;
  // 要は半分に分割している
  // 0文字目からn文字
  string a = t.substr(0, n);
  // n文字目以降
  string b = t.substr(n);
  // 逆にしておく
  reverse(b.begin(), b.end());
  string x = a + b;
  // Z algorithmは各iについて「S と S[i:|S|-1] の最長共通接頭辞の長さ」を記録した配列AをO(|S|)
  // で求めるアルゴリズム
  vector<int> za_x = z_algorithm(x);
  za_x.push_back(0);
  debug(za_x);

  // bとaを反対に組み合わせたものに対しても求める
  string y = b + a;
  vector<int> za_y = z_algorithm(y);
  za_y.push_back(0);
  debug(za_y);

  for (int i = 0; i <= n; i++) {
    debug(i);
    debug(2 * n - i);
    debug(n + i);
    debug(za_x[2 * n - i]);
    debug(za_y[n + i]);
    // この値がiになれば良い(とりうる最大値)
    // i文字目まで進んだ時に、xの2*n-1文字以降が一致している必要がある
    if(za_x[2 * n - i] < i) continue;
    // この値がn-iになれば良い(とりうる最大値)
    // このとき残りの文字列がひっくり返した文字列の先頭と一致している必要がある
    if(za_y[n + i] < n - i) continue;
    // Z(X)[2N−i]=i かつ Z(Y)[N+i]=N−i
    // ならば条件を満たすのでその時の値を出力して終わり
    cout << t.substr(0, i) + t.substr(n + i) << endl;
    cout << i << endl;
    return 0;
  }

  cout << -1 << endl;
  return 0;
}