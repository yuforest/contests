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
const ll INF = ll(1e18);


int N, A[400009];
int v = 0;
// 1 手で机に残ったクッキーの XOR を 0 にできれば先手必勝。そうでなければ後手必勝 ... 1
// v=A1 XOR A2 XOR...XOR ANとする時、A1,A2,A3...ANのいずれかがvと一致していれば
// 先手必勝、そうでなければ後手必勝...2
// 1と2は同値
int main() {
  // Step #1. 入力
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> A[i];

  // Step #2. A[1] xor A[2] xor ... xor A[N] を計算する
  for (int i = 1; i <= N; i++) v ^= A[i];
  // Step #3. 場合分け・出力
  // 奇数の場合先手必勝
  // 奇数の時には2手後にゲームが終わることはない
  // 2手後にXORが0になるためには、1番目にとったものと2番目にとったもののペアで
  // 全てのXORが0になるようなペアが存在することが必要で先手が何をとったとしても
  // そのような状況が成り立つ必要がある
  // しかしそのペアはあるとしてもN/2個なので、1つは必ず余ってしまう
  // この一つをとると、その時点で先手が勝つか、次に後手がどのクッキーをとっても勝つことはできない
  // 例えば1,2,3,4,5の数字があるとする
  // このとき先手が1を取ればその時点で勝つ(v=1^10^11^100^101^=001なので)
  // 先手が2を取るとき後手が3を取れば勝つ(001^11=010,010^10=0)
  // 先手が3を取る時後手は2を取れば良い(上とペア)
  // 先手が4を取る時後手は5を取れば良い(001^100=101,101^101=0)
  // 先手が5を取る時後手は4を取れば良い(001^101=100,100^100=0)
  // よって先手がとった後、後手がXORを0にする方法が必ずしもあるとは限らないので
  // つまり先手がとった後に勝つか、後手がその後にとって先手に戻ってくる
  // 先手が最適な手を取れば、最後にはクッキーが1つになって先手が勝つ
  if (N % 2 == 1) {
    cout << "Win" << endl;
  } else {
    bool winning = false;
    // そうでない時全てのXORと一致するA[i]があれば先手必勝
    // 一度で勝てない時に上の奇数の状況と同じになってしまう
    // そうなれば後手が最適な手を取り続けることで先手は負ける
    for (int i = 1; i <= N; i++) {
      if (A[i] == v) winning = true;
    }
    if (winning == true) cout << "Win" << endl;
    else cout << "Lose" << endl;
  }
  return 0;
}