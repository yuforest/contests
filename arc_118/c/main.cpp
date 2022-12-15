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

int ans[2010];

// greatest common divisor
ll gcd(ll a, ll b) { return a ? gcd(b % a, a) : b; }
// least common multiple
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main() {
  ll N;
  cin >> N;
  // N=3の時は小さい方から選ぶと6 10 12になり条件を満たさないのでコーナーケース
  if (N == 3) {
    cout << 6 << " " << 10 << " " << 15 << endl;
    return 0;
  }
  // それ以外の時は6,10,15の倍数を小さい方から出力してあげれば問題ない
  // gcd(6, 10) = 2
  // gcd(6, 15) = 3
  // gcd(10, 15) = 5
  // gcd(6,10,15) = 1
  // 2つのgcdが素数になるものを小さい方から3つ作れるような組み合わせで最小のものが6,10,15
  // gcd(gcd(6,10),15)=1となる
  // 倍数に関しても例えば12ならgcdを考えると6は言わずもがな10や15に対しても1より大きい数字になる
  // gcd(12,10)=2, gcd(12,15)=3のような形で
  // 考察系の問題
  // 互いに2つのgcdが異なる素数になり、3つのgcdが1になる3つの数の倍数も条件を満たすことに気づく
  // まず具体例で倍数を追加して条件を満たすか確認する
  // 2つのgcdが素数になる3つのセットを探す
  set<ll> st;
  for(ll i = 6; i<= 10000; i+=6) st.insert(i);
  for(ll i = 10; i<= 10000; i+=10) st.insert(i);
  for(ll i = 15; i<= 10000; i+=15) st.insert(i);
  debug(st.size());
  ll count = 0;
  for(auto x: st) {
    if (count!=0) cout << " ";
    cout << x;
    count++;
    if(count == N) break;
  }
  cout << endl;
}