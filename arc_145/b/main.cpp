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

ll N, A, B;
// nは始めの石の個数
// n mod A < B と1 <= n <= Xを共に満たすnの個数
ll f(ll X) {
  // X mod Aは1,2,..., A-1, 0, 1, 2...と周期的になっている
  // Xの中にはAが(X/A)個だけ入るので、その部分にA, Bの小さい方をかければ、
  // A*(X/A)までに関しては解が求まる、A<=BであればBは勝つことができないので前半の数字はA*(X/A)となる
  // n=13, A=5, B=3を考えると5,6,7に関してはAliceは1回とった後Bobは取ることができない
  // 8,9に関してはBobが取り、勝つことができる
  // つまりAの倍数からB回はAliceが勝つことができる
  // 後半はA*(X/A)+1からXまでの解であり、これはXをAで割った余り(これが最大値)か、
  // B-1(これはXの倍数から最初のB回は勝つことができるが、後半の区間にはA*(X/A)は入っていないので
  // 1を引く必要がある
  return (X / A) * min(A, B) + min(X % A, B - 1);
}

int main() {
  cin >> N >> A >> B;
  // Aliceがかつ必要十分要件は
  // n >= A && n mod A < B
  // A > nの場合答えは0(初回のターンで取ることができないから)
  // fは引数が大きければ戻り値も大きい単純増加な関数といえるのでA > nの場合は
  // 必ず0以下になる
  cout << max(f(N) - f(A-1), 0LL) << endl;
  return 0;
}