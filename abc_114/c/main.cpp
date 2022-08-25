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

int ans[2010];

int v[3] = { 3,5,7 };
// 入力
long long N;

// int main() {
//   cin >> N;
//   int ans = 0;

//   // 3桁から10桁まで探索
//   rep3(dgt, 3, 10) {
//     int ma = 1;
//     // 各桁357のいずれかになる組み合わせ、3の何乗通りあるか(3桁なら3^3通り)
//     rep3(i, 0, dgt) ma *= 3;

//     // 3進数のbit全探索的なことをやる(3桁なら0,1,2...26)
//     rep3(msk, 0, ma) {
//       int x = 0;
//       int m = msk;
//       int cn[3] = { 0, 0, 0 };
//       // 現在の桁数分やる
//       rep3(i, 0, dgt) {
//         // 「3のあまりを見て、3で割る」というのを繰り返せば下の桁から数が取得できる
//         int d = m % 3;
//         x = x * 10 + v[d];
//         // 現在の桁の数字に応じてインクリメント
//         cn[d]++;
//         m /= 3;
//       }
//       // N以下でカウンタが全て0より大きければカウント
//       if (x <= N and 0 < cn[0] and 0 < cn[1] and 0 < cn[2]) ans++;
//     }
//   }

//   cout << ans << endl;
//   return 0;
// }



// 別解(再起関数で解ける)
// cur: 現在の値、use: 7, 5, 3 のうちどれを使ったか, counter: 答え
void func(long long cur, int use, long long &counter){
  if (cur > N) return; // ベースケース、Nより大きくなったら枝刈り
  if (use == 0b111) ++counter; // 答えを増やす

  // 7 を付け加える
  func(cur * 10 + 7, use | 0b001, counter);

  // 5 を付け加える
  func(cur * 10 + 5, use | 0b010, counter);

  // 3 を付け加える
  func(cur * 10 + 3, use | 0b100, counter);
}

int main() {
  cin >> N;
  long long res = 0;
  func(0, 0, res);
  cout << res << endl;
}