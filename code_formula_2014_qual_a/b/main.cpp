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

char pin_notation(int index) {
  if (index == 0) return 'x';
  if (index == 1) return '.';
  return 'o';
}

int ans[2010];

int main() {
  int a, b;
  cin >> a >> b;
  vi pins(10, 0);
  rep(i, a) {
    int val;
    cin >> val;
    pins[val] = 1;
  }
  rep(i, b) {
    int val;
    cin >> val;
    pins[val] = 2;
  }
  vs ans;
  rep(i, 4) {
    string tmp = "";
    if (i == 0) {
      tmp += pin_notation(pins[7]);
      tmp += " ";
      tmp += pin_notation(pins[8]);
      tmp += " ";
      tmp += pin_notation(pins[9]);
      tmp += " ";
      tmp += pin_notation(pins[0]);
    }
    if (i == 1) {
      tmp += " ";
      tmp += pin_notation(pins[4]);
      tmp += " ";
      tmp += pin_notation(pins[5]);
      tmp += " ";
      tmp += pin_notation(pins[6]);
    }
    if (i == 2) {
      tmp += "  ";
      tmp += pin_notation(pins[2]);
      tmp += " ";
      tmp += pin_notation(pins[3]);
    }
    if (i == 3) {
      tmp += "   ";
      tmp += pin_notation(pins[1]);
    }
    ans.push_back(tmp);
  }
  rep(i, 4) {
    cout << ans[i] << endl;
  }
  return 0;
}