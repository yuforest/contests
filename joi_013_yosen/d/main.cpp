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

#define MOD 10007
template <int mod>
struct ModInt {
  int x;
  ModInt() : x(0) {}
  ModInt(int64_t y)
      : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}
  ModInt &operator+=(const ModInt &p) {
    if((x += p.x) >= mod) x -= mod;
    return *this;
  }
  ModInt &operator-=(const ModInt &p) {
    if((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }
  ModInt &operator*=(const ModInt &p) {
    x = (int)(1LL * x * p.x % mod);
    return *this;
  }
  ModInt &operator/=(const ModInt &p) {
    *this *= p.inverse();
    return *this;
  }
  ModInt operator-() const { return ModInt(-x); }
  ModInt operator+(const ModInt &p) const {
    return ModInt(*this) += p;
  }
  ModInt operator-(const ModInt &p) const {
    return ModInt(*this) -= p;
  }
  ModInt operator*(const ModInt &p) const {
    return ModInt(*this) *= p;
  }
  ModInt operator/(const ModInt &p) const {
    return ModInt(*this) /= p;
  }
  bool operator==(const ModInt &p) const {
    return x == p.x;
  }
  bool operator!=(const ModInt &p) const {
    return x != p.x;
  }
  ModInt inverse() const {
    int a = x, b = mod, u = 1, v = 0, t;
    while(b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ModInt(u);
  }
  ModInt pow(int64_t n) const {
    ModInt ans(1), mul(x);
    while(n) {
      if(n & 1) ans *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ans;
  }
  friend ostream &operator<<(ostream &os, const ModInt &p) {
    return os << p.x;
  }
  friend istream &operator>>(istream &is, ModInt &a) {
    int64_t t;
    is >> t;
    a = ModInt<mod>(t);
    return (is);
  }
  static int get_mod() { return mod; }
};

long long n;
string s;
vector<long long> v;
// dp[i][S]=i 日目に参加した部員の状態がSであるような、1からi日目までの部員の組み合わせの通り数
vector<vector<ModInt<MOD>>> dp;

ModInt<MOD> solve();

int main() {
  cin >> n >> s;

  cout << solve() << endl;
  return 0;
}

ModInt<MOD> solve() {
  // Sを全て見て文字に応じた数字を挿入
  for(int i = 0; i < n; ++i)
    if(s[i] == 'J')
      v.push_back(0);
    else if(s[i] == 'O')
      v.push_back(1);
    else
      v.push_back(2);

  // N+1と8(2^3)の配列を作成
  dp.assign(n + 1, vector<ModInt<MOD>>(8, 0));
  // 0日目において鍵はJ君が持っている
  dp[0][1] = 1;
  // N日を全探索
  for(int i = 0; i < n; ++i) {
    // 次の日に参加する人の状態数を全探索
    for(int j = 0; j < 8; ++j)
      // 責任者が参加しているかどうか(していなければ遷移できない)
      if((j >> v[i]) & 1)
        // 今日の参加者の状態数を全探索
        for(int k = 0; k < 8; ++k)
          // 翌日と今日でどちらも参加している人がいる(鍵を持って帰る人がいる)
          if(j & k) dp[i + 1][j] += dp[i][k];
  }
  ModInt<MOD> ans(0);
  // 最終日の状態数を全探索した和が答えとなる
  for(int i = 0; i < 8; ++i) ans += dp[n][i];
  debug(dp);
  return ans;
}