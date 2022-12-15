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

int n;
int a[20][20];
vector<pair<int, int>> vec;
bool used[20];
// 各ペアの 1 人目はその時点で残っている人の中で番号が最小の参加者とする」ように改良
// することで各ペアの1人目が一通りに定まるため15*13*11*...1=2027025通りに改善される
// 無駄な探索をやめる
// ペア(1,2)と(2,1)は同じなので、残っている人からペアを選ぶ際に
// 1人目は小さい数字の人で固定してしまって良い
// また組み合わせ{(1,2),(3,4)}と{(3,4),(1,2)}は同じなので
// (3,4)のペアを探索するときに(1,2)が残っている必要はない
// N=3で6人の場合、まず最初に1とのペアを作るので
// 独立に(1,2),(1,3),(1,4),(1,5),(1,6)のペアができることになる
// ここで(1,2)のペアを深掘りして考えてみる
// このとき残っている人は{3,4,5,6}である
// 次に3とのペアを作るので(3,4),(3,5),(3,6)のペアができることになる
// ここで(3,4)のペアに関して深掘りする
// このとき残っている人は{5,6}である
// 5とのペアを作るので(5,6)の一通りとなる
// これと同じことを他の数字でもやればペアの順番や組み合わせの順番を変えても
// 重複しない組み合わせを作ることができる
// 例えば最初の時点で(1,3)を深掘りしてみることにする
// このとき残っている数は{2,4,5,6}である
// 最小の2とのペアは(2,4),(2,5),(2,6)である
// (2,4)に関して深掘りする
// このとき残っている数字は{5,6}である
// よって{5,6}をペアとする
// 最初の例と比べてみると{(1,2),(3,4),(5,6)}と{(1,3),(2,4),(5,6)}となる
// このような形で異なるペアの組み合わせを作ることができる
// ペアの先頭1人を数字が小さいものに固定し、さらに先のペアの最初の人は後のペアの最初の人より
// 小さな数字になるように実装することで重複したペアの組み合わせを避けることができる
// 汎用的な考え方としては全探索の計算量削減に近い
int calc() {
  // 全ての組み分けが完了したら、
  // XORを計算して結果を返す
  // ベースケース
  if(vec.size() == n){
    int ret = 0;
    // このときp.firstはp.secondより必ず小さくなるため
    // 相性の配列の大小を気にしなくて良い
    for(auto p : vec) ret ^= (a[p.first][p.second]);
    return ret;
  }

  int l;
  // まだ組みが決まっていない人の中で最小の人を選ぶ
  for(int i = 1; i <= 2*n; i++){
    if(!used[i]){
      l = i;
      break;
    }
  }
  // 使用済みにロックする
  used[l] = true;
  int ret = 0;
  for(int i = 1; i <= 2*n; i++){
    if(!used[i]){
      // 追加したペアを追加して、iもロックする
      vec.push_back({l, i}), used[i] = true;
      // ここで最大値更新、DFS的に探索する
      // DFSで探索した結果最初に呼び出されたcalcのこの値に最大値が入り返される
      ret = max(ret, calc());
      // 追加したペアを解放して、iも解放する(後のループではiが使われるため)
      vec.pop_back(), used[i] = false;
    }
  }
  // 使用済みを解放する
  used[l] = false;
  return ret;
}

int main(void) {
  cin >> n;
  // 入力を受け取る
  for(int i = 1; i <= 2*n-1; i++){
    for(int j = i+1; j <= 2*n; j++){
      // 例えば最初の行は2列目から2N列目まで数字が入る
      // 2行目は3列目から2N列目まで数字が入る
      cin >> a[i][j];
    }
  }
  cout << calc() << endl;
  return 0;
}