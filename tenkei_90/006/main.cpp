// 標準ライブラリを全て読み込む
// 本書では細かく書きませんが、下記リンクが参考になります
// https://atcoder.jp/contests/apg4b/tasks/APG4b_af
#include <bits/stdc++.h>
// stdのstd::cinのような書き方ではなくcinと書けば良くなる
using namespace std;

// デバッグ用マクロ
// 本書では細かく書きませんが、下記リンクが参考になります
// https://naskya.net/post/0002/
#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

// データ構造の省略
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

// modの計算
long long mod1 = 1000000007;
long long mod2 = 998244353;

// 隣接グラフ(1 << 18は2^18で262144となる)
vector<ll> G[1 << 18];

// ACL(AtCoder Library)、普段はコメントアウトしてある
// #include <atcoder/all>
// using namespace atcoder;

// repマクロ
// 0からn-1まで
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// aからb−1まで
#define rep3(i,a,b) for(int i=a;i<b;i++)
// n-1から0まで
#define per(i, n) for (int i = int(n) - 1; i >= int(0); i--)
// b-1からaまで
#define per3(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
// 範囲for文の省略
#define fore(i,a) for(auto &i:a)
// sort(A.begin(), A.end())をsort(all(A))のように書けます
#define all(x) (x).begin(), (x).end()

// 最大値と最小値の更新
// 返り値は更新した場合はtrue、そうでなければfalse
template <typename T>
inline bool chmax(T &a, T b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T>
inline bool chmin(T &a, T b) {
  return ((a > b) ? (a = b, true) : (false));
}

string S;
int N,K;
int nex[100009][26];

int main() {
  // Step #1. 入力
  cin >> N >> K;
  cin >> S;

  // Step #2. 前計算
  // 各文字の最後は文字列サイズにしておく
  for (int i = 0; i < 26; i++) nex[S.size()][i] = S.size();
  // 最後の文字から見ていく
  // 前選んだ文字の右にある文字cの中で最も左のもの
  for (int i = (int)S.size() - 1; i >= 0; i--) {
    // 26文字を見ていく
    for (int j = 0; j < 26; j++) {
      // 今見ている文字が一致したら
      if ((int)(S[i] - 'a') == j) {
        // 今のiのインデックスを入れる
        nex[i][j] = i;
      }
      else {
        // そうでなければ次の文字の値を入れる
        nex[i][j] = nex[i + 1][j];
      }
    }
  }

  // Step #3. 一文字ずつ貪欲に決める
  string Answer = "";
  int CurrentPos = 0;
  // どこまで選んだか
  for (int i = 1; i <= K; i++) {
    for (int j = 0; j < 26; j++) {
      // 次にこの文字を選ぶとしたらそれはどこにあるのか
      int NexPos = nex[CurrentPos][j];
      // 次に選ぶ文字以降を全て選んだ時に構築できる文字数
      int MaxPossibleLength = (int)(S.size() - NexPos - 1) + i;
      // これがK以上である必要がある
      if (MaxPossibleLength >= K) {
        // 答え更新
        Answer += (char)('a' + j);
        // 今の位置を更新
        CurrentPos = NexPos + 1;
        // 内側のループを抜ける
        break;
      }
    }
  }

  // Step #4. 出力
  cout << Answer << endl;
  return 0;
}