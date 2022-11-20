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
#define rrep(i,a,b) for(int i=a;i>=b;i--)

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

// 整数をmodで扱えるもの
//---------------------------------------------------------------------------------------------------
template<int MOD> struct ModInt {
    static const int Mod = MOD;
    unsigned x;
    ModInt() : x(0) { }
    ModInt(signed sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
    ModInt(signed long long sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
    int get() const { return (int)x; }
    ModInt &operator+=(ModInt that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator-=(ModInt that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }
    ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }
    ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
    ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
    ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
    ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
    ModInt inverse() const { long long a = x, b = MOD, u = 1, v = 0;
        while (b) { long long t = a / b; a -= t * b; std::swap(a, b); u -= t * v; std::swap(u, v); }
        return ModInt(u); }
    bool operator==(ModInt that) const { return x == that.x; }
    bool operator!=(ModInt that) const { return x != that.x; }
    ModInt operator-() const { ModInt t; t.x = x == 0 ? 0 : Mod - x; return t; }
};
template<int MOD> ostream& operator<<(ostream& st, const ModInt<MOD> a) { st << a.get(); return st; };
template<int MOD> ModInt<MOD> operator^(ModInt<MOD> a, unsigned long long k) {
  ModInt<MOD> r = 1;
  while (k) {
    if (k & 1) r *= a;
    a *= a;
    k >>= 1;
  }
  return r;
}
// 二項係数ライブラリ
template<typename T, int FAC_MAX> struct Comb {
  vector<T> fac, ifac;
  Comb(){
    fac.resize(FAC_MAX,1);
    ifac.resize(FAC_MAX,1);
    // 階乗の配列を作成
    rep3(i,1,FAC_MAX) fac[i]=fac[i-1]*i;
    // 最後の位置に逆数を入れている
    ifac[FAC_MAX-1]=T(1)/fac[FAC_MAX-1];
    // フェルマーの小定理: ある数xのmodp(pは素数)上での逆数はx'=x^(p-2)で計算できる
    // ここでは4038から1まで反対に見ていく、逆数を計算
    rrep(i,FAC_MAX-2,1) ifac[i] = ifac[i+1] * T(i+1);
  }
  T aPb(int a, int b) { if (b < 0 || a < b) return T(0); return fac[a] * ifac[a - b]; }
  // a!/(a-b)!b!の値、割り算をmod1000000007の逆数をかけることで表している
  T aCb(int a, int b) { if (b < 0 || a < b) return T(0); return fac[a] * ifac[a - b] * ifac[b]; }
  // x1+x2+⋯+xk=nx1+x2+⋯+xk=n(k個に分割したボールの数を合計するとn)
  // xi は 0 以上の整数
  // ここでnがグループ数、kが球の数
  T nHk(int n, int k) {
    if (n == 0 && k == 0) return T(1);
    if (n <= 0 || k < 0) return 0;
    // 一般に a 個の玉と b 個の仕切りを並べる方法の数は
    // a+bCa通り(=a+bCbでもある)であり、k個の玉と、n-1個の仕切りの並びから、
    // 答えは n+k−1Ck通りとなる
    return aCb(n + k - 1, k);
  } // nHk = (n+k-1)Ck : n is separator
  T pairCombination(int n) {if(n%2==1)return T(0);return fac[n]*ifac[n/2]/(T(2)^(n/2));}
  // combination of paris for n
};
typedef ModInt<1000000007> mint;
//---------------------------------------------------------------------------------------------------

Comb<mint, 4040> com;
//---------------------------------------------------------------------------------------------------
int N, M;
vector<int> E[101010];
int S, T;
ll dst[101010][3];
int vis[101010][3];
int main() {
  cin >> N >> M;
  rep3(i, 0, M) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    E[a].push_back(b);
  }
  cin >> S >> T; S--; T--;

  queue<pair<int, int>> que;

  que.push({ S, 0 });
  vis[S][0] = 1;
  // dst[cu][jmp] := 頂点cuにjmp歩目で到達したときの最短距離
  // 訪問済み頂点に戻ったらそれ以上は探索しないので、到達できない場合にはBFSが終了する
  while (!que.empty()) {
    int cu, jmp;
    tie(cu, jmp) = que.front(); que.pop();

    // けんけんぱは3回で1セットなので3で割っている
    if (cu == T and jmp == 0) {
      cout << dst[cu][jmp]/3 << endl;
      return 0;
    }
    // jmp2は次に訪問する頂点がけんけんぱのどの位置なのかを示している
    // 0なら止まっている、それ以外なら移動中
    int jmp2 = (jmp + 1) % 3;
    // 今の頂点から訪問できる頂点を訪問
    fore(to, E[cu]) {
      // 訪問済みでなければ訪問
      if (!vis[to][jmp2]) {
        // 訪問済みにしている
        vis[to][jmp2] = 1;
        // 移動距離は現在の頂点から1移動したもの
        dst[to][jmp2] = dst[cu][jmp] + 1;
        que.push({ to, jmp2 });
      }
    }
  }

  cout << -1 << endl;
}
