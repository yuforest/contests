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
#define all(x) (x).begin(), (x).end()
#define fore(i,a) for(auto &i:a)

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

// MODを扱うクラス
// MODをコンパイル時に与えるバージョン
template <long long MOD>
class ModInt {
  public:
   constexpr ModInt(long long x = 0LL) noexcept {
      if (0 <= x && x < MOD) {
         x_ = x;
      } else {
         x_ = x % MOD;
 
         if (x_ < 0) {
            x_ += MOD;
         }
      }
   }
 
   // MODを返す
   constexpr long long GetMod() const {
      return MOD;
   }
 
   // MOD未満であることが保証されている値の場合、modを取らずにModIntオブジェクトを生成する
   void SetRawValue(long long x) {
      x_ = x;
   }
 
   static constexpr ModInt raw(long long x) {
      ModInt res;
      res.SetRawValue(x);
 
      return res;
   }
 
   // 値を返す
   constexpr long long value() const noexcept {
      return x_;
   }
 
   // 四則演算
   constexpr ModInt operator+() const noexcept {
      return *this;
   }
 
   constexpr ModInt operator-() const noexcept {
      return ModInt(-x_);
   }
 
   constexpr ModInt& operator+=(const ModInt& rhs) noexcept {
      x_ += rhs.value();
 
      if (x_ >= MOD) {
         x_ -= MOD;
      }
 
      return *this;
   }
 
   constexpr ModInt& operator++() noexcept {
      x_++;
 
      if (x_ == MOD) {
         x_ = 0;
      }
 
      return *this;
   }
 
   constexpr ModInt operator++(int) noexcept {
      ModInt res = *this;
      ++(*this);
 
      return res;
   }
 
   constexpr ModInt& operator-=(const ModInt& rhs) noexcept {
      x_ += MOD - rhs.value();
 
      if (x_ >= MOD) {
         x_ -= MOD;
      }
 
      return *this;
   }
 
   constexpr ModInt& operator--() noexcept {
      if (x_ == 0) {
         x_ = MOD;
      }
 
      x_--;
 
      return *this;
   }
 
   constexpr ModInt operator--(int) noexcept {
      ModInt res = *this;
      --(*this);
 
      return res;
   }
 
   constexpr ModInt& operator*=(const ModInt& rhs) noexcept {
      x_ *= rhs.value();
      x_ %= MOD;
 
      return *this;
   }
 
   // 繰り返し二乗法でx^nを求める
   // 計算量: O(log n)
   constexpr ModInt pow(long long n) const;
 
   // 逆元を返す
   // @pre modが素数であること
   // 計算量: O(log P)
   constexpr ModInt inv() const noexcept {
      return pow(MOD - 2);
   }
 
   constexpr ModInt& operator/=(const ModInt& rhs) noexcept {
      return (*this) *= rhs.inv();
   }
 
   constexpr ModInt operator/(const ModInt rhs) const noexcept {
      return ModInt(*this) /= rhs;
   }
 
   friend ostream& operator<<(ostream& os, const ModInt& rhs) {
      os << rhs.value();
      return os;
   }
 
   friend constexpr ModInt operator+(const ModInt& lhs, const ModInt& rhs) noexcept {
      return ModInt(lhs) += rhs;
   }
 
   friend constexpr ModInt operator-(const ModInt& lhs, const ModInt& rhs) noexcept {
      return ModInt(lhs) -= rhs;
   }
 
   friend constexpr ModInt operator*(const ModInt& lhs, const ModInt& rhs) noexcept {
      return ModInt(lhs) *= rhs;
   }
 
   friend constexpr bool operator==(const ModInt& lhs, const ModInt& rhs) noexcept {
      return lhs.value() == rhs.value();
   }
 
   friend constexpr bool operator!=(const ModInt& lhs, const ModInt& rhs) noexcept {
      return lhs.value() != rhs.value();
   }
 
  private:
   long long x_;
};

template <long long MOD>
constexpr ModInt<MOD> ModInt<MOD>::pow(long long n) const {
  ModInt<MOD> val(1);
  ModInt<MOD> x(x_);

  while (n > 0) {
    if ((n & 1LL) == 1) {
      // iビット目が1の場合、x^(2^i)をかける
      val *= x;
    }

    x *= x;
    n = n >> 1;
  }

  return val;
}

using mint = ModInt<1000000007>;
using P = pair<int, int>;

int main() {
  int N;
  cin >> N;

  vector<vector<int>> adj_list(N, vector<int>());  // 隣接リスト

  rep(i, N - 1) {
    int a, b;
    cin >> a >> b;

    a--;
    b--;

    adj_list[a].push_back(b);
    adj_list[b].push_back(a);
  }

  // 部分木のサイズを求める
  map<P, int> tree_size;  // (i, j) -> ノードiを親、ノードjをrootとする部分木のサイズ

  auto dfs = [&adj_list, &tree_size](auto dfs, int i, int parent) -> int {
    int size = 1;

    for (auto j : adj_list[i]) {
      if (j == parent) {
        continue;
      }

      int child_size = dfs(dfs, j, i);
      size += child_size;
    }

    return tree_size[{parent, i}] = size;
  };

  dfs(dfs, 0, -1);

  // ノードiを親、ノードjをrootとする部分木のサイズを返す
  auto get_tree_size = [&N, &tree_size](int i, int j) {
    if (tree_size[{i, j}]) {
      return tree_size[{i, j}];
    } else {
      return N - tree_size[{j, i}];
    }
  };

  // ノードjをrootとする部分木Tの頂点の少なくとも1つが黒になる確率を返す
  auto p_b = [&get_tree_size](int i, int j) {
    int size = get_tree_size(i, j);
    // 2分の1を作っている
    mint half = 1;
    half /= 2;

    // 1 - (1/2)^size
    // 少なくとも1つが黒になるの余事象は全てが白になる
    // よって(1/2)^sizeを1から引く
    mint prob = 1;
    prob -= half.pow(size);
    return prob;
  };

  mint ans = 0;

  rep(i, N) {
   // ノードiが「穴あき」になる期待値を求める
   //  1と2の時に部分木が穴あきになることはない
   if (adj_list[i].size() < 2) {
     continue;
   }

   mint p_0 = 1;

   for (auto j : adj_list[i]) {
     p_0 *= 1 - p_b(i, j);
   }

   mint p_1 = 0;

   for (auto j : adj_list[i]) {
     p_1 += p_b(i, j) / (1 - p_b(i, j));
   }

   p_1 *= p_0;
   // 黒い頂点を含む最小の部分木をS
   // ここから頂点iがSに含まれる確率P(i∈S)は頂点iと隣接する部分木で黒を含む部分木が0個, 1個になる確率をP0(i),P1(i)として
   // P(i∈S)=1/2(1−P0(i)−P1(i))
   // 最初の1/2は頂点iが白になる確率
   ans += (1 - p_0 - p_1) / mint(2);
  }

  cout << ans << endl;

  return 0;
}