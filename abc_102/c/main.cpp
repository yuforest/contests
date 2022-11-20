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

int N, A[201010];
int main() {
  // マンハッタン距離の差の総和を最小化するときは中央値を使う
  // abs(A[1]-(b+1)) + abs(A[2]-(b+2)) + ... + abs(A[N] - (b + N))を変形
  // abs( (A[1]-1)-b) + abs( (A[2] - 2) - b) + ... + abs( (A[N]-N) - b)
  // B[i] = A[i] - iとするとabs(B[1] - b) + abs(B[2] - b) + ... + abs(B[N] - b)を最小化する問題
  // 新しい配列をソートして、その中央値を探し、差の和を取るとそれが最小になる
  // |x−B1|+|x−B2|+⋯+|x−BN|  を最小にする x は、B1,B2,…,BN のメディアン(Bはソート済み)
  // xが左側に寄っているときは、右へ動かすと 差の総和を減らすことができる
  // xが右側に寄っているときも同様に、左へ動かすと 差の総和を減らすことができる
  // このバランスがとれるのが、ちょうどメディアンの場合
  // n が偶数の場合はメディアンは2つあって、その間の区間内はすべて最小値
  cin >> N;
  rep(i, N) {
    cin >> A[i];
    A[i] -= (i + 1);
  }
  // ソート
  sort(A, A + N);

  // 中央値を取る、配列の個数が奇数の時と偶数の時で場合分け
  int b;
  if (N % 2 == 1) b = A[N / 2];
  // メディアンが小数になるような場面でも2つのメディアンの区間内は全て最小値になるため問題ない
  else b = (A[N / 2 - 1] + A[N / 2]) / 2;

  ll ans = 0;
  // 中央値との差を取っている
  rep(i, N) ans += abs(A[i] - b);
  cout << ans << endl;
  return 0;
}