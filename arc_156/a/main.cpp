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

int solve() {
  int n;
  string s;
  cin >> n >> s;
  int one = count(s.begin(), s.end(), '1');
  // 奇数なら達成不可能
  if(one & 1) return -1;
  bool adj = 0;
  // 隣接した1があるか
  for(int i = 0; i < n - 1; i++)
      if(s[i] == '1' and s[i] == s[i + 1]) adj = 1;
  // 1の数が4以上かつ隣接していないなら2で割ればいい
  if(one != 2 or !adj) return one / 2;
  // 文字数3で1の数が2で隣接している場合は達成不可能
  if(n == 3) return -1;
  // 文字数4で1の数が2で隣接しており、0110の時は3回の操作が必要
  if(n == 4 and s == "0110") return 3;
  // それ以外の時は2回の操作が必要
  return 2;
}
int main() {
  int t;
  cin >> t;
  while(t--) cout << solve() << endl;
}