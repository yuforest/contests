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


constexpr int MAX = 30;
long long dp[MAX + 1][MAX + 1];
// Aの使える回数とBの使える回数と辞書順で何番目の文字列かを示す数を引数に取る
string find_kth(int A, int B, long long K) {
  if (A == 0) {
    // bがB個からなる文字列
    return string(B, 'b');
  }
  if (B == 0) {
    // aがA個からなる文字列
    return string(A, 'a');
  }
  // 先頭から決めていっている
  // aが選択された場合は答えに追加するだけでいいが、
  // bが選択された場合は、a?????????がスキップされることになる
  debug(K);
  debug(dp[A - 1][B]);
  // dp[A - 1][B]は先頭にaを選んだ場合の他の文字の並べ方の組み合わせを示しているので
  // K <= dp[A - 1][B]であれば、先頭にaを配置した後に
  // 残りの文字を並べることによってK番目の文字列を作ることができることを示している
  if (K <= dp[A - 1][B]) {
    // aが先頭に来るということはbが先頭に来るのと比べて辞書順の並びをスキップしていない
    // ことになる
    // よってaを使える回数を1減らして再帰関数を実行すればよい
    return string("a") + find_kth(A - 1, B, K);
  } else {
    // この時はaをA-1個、bをB個使った文字列がスキップされていることになる
    // bが先頭に近い方にくるということは辞書順でaが先にくる文字列をスキップしていると
    // いうことになる
    // example: A=2, B=2, K=4
    // ここでbを用いるということはここにaが来た場合にありうるaabb, abba, ababという
    // 3つの文字列をスキップしていることになる
    // スキップした後はaを2個、bを1個使った文字列でK-3=4-3=1番目の文字列を
    // 求めれば良いのでK - dp[A - 1][B]として再帰関数を実行する
    return string("b") + find_kth(A, B - 1, K - dp[A - 1][B]);
  }
}
int main() {
  int A, B;
  long long K;
  cin >> A >> B >> K;
  // aがi個bがj個からなる文字列の総数をあらかじめ計算しておく
  // (0,0)からスタートし、x軸の正の方向あるいはy軸の正の方向に1進むことを繰り返して(i,j)に至る方法の総数に等しい
  // つまり空文字列から始まって選ぶものがa or bのみなのでi方向への移動をaを選ぶという行動、
  // j方向への移動をbを選ぶという行動に対応させることができる
  // i=0,j=0の時空文字列
  dp[0][0] = 1;
  for (int i = 0; i <= A; ++i) {
    for (int j = 0; j <= B; ++j) {
      if (i > 0) {
        dp[i][j] += dp[i - 1][j];
      }
      if (j > 0) {
        dp[i][j] += dp[i][j - 1];
      }
    }
  }
  debug(dp);
  cout << find_kth(A, B, K) << '\n';
  return 0;
}
