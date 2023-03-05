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

int main() {
  int n;
  cin >> n;
  vector<int> c(10);
  for(int i = 1; i <= 9; i++) cin >> c[i];
  // 最小コスト
  int mn = *min_element(c.begin() + 1, c.end());
  // 桁数を最大化したいので最初に最大の桁数を決める
  int length = n / mn;
  string ans = "";
  // 貪欲的に見ていくO(N)
  for(int i = 0; i < length; i++) {
    // 9から順に見ていく、桁数が同じなら上位の桁の数字は大きい方が良い
    for(int j = 9; j >= 1; j--) {
      // 最小コスト*残りの桁数+今の桁のコストがn以下ならそれを選択する
      if((ll)mn * (length - 1 - i) + c[j] <= n) {
        // コストを引く
        n -= c[j];
        // 今の桁を足す
        ans.push_back((char)('0' + j));
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}