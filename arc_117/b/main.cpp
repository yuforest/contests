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


long long N, A[1 << 18], Q[1 << 18];
long long Answer = 1;

int main() {
  // N=2の時を考える
  // P1=2つのビルが存在する階の数
  // P2=1つのビルが存在する階の数
  // P1: 0個からmin(A1, A2)個までのmin(A1, A2)+1通りありうる
  // P2: 0個からmax(A1, A2) - min(A1, A2)個までのmax(A1, A2) - min(A1, A2)+1通りありうる
  // 答えは(min(A1, A2)+1) * (max(A1, A2) - min(A1, A2)+1)通りとなる
  int N;
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> A[i];
  // 昇順ソート
  sort(A + 1, A + N + 1);
  // A[i] - A[i-1]をQに保存する
  // 例えば2番目に小さい高さのビルが一番小さいビルに追いつくまでにはA[2] - A[1]回の操作をする必要があり
  // その操作をするごとに景観は変化する
  // N個全てのビルにその階があるビルの個数はA[1](=Q[1])となる
  // N-1個のビルにその階があるビルの個数はA[2]-A[1](Q[2])となる(同じ階数を持つビルがない場合)
  // 同じ階数をもつビルがある場合(iとi+1のビルが同じ階数の場合)、Q[i+1]は1になる
  // 最初にビルがi個存在する階がQ[i]個ある
  // 最終的な景観でビルがi個存在する階は0個からQ[i]個までのQ[i]+1通りある
  // この領域の話は独立に考えることができる
  // 例えばN=3で3つのビルが共通である階数が2回、2つのビルが共通で持っている数が2回、1つのビルが持っている数が3階だとする
  // つまりA = {2, 4, 7}のような時である
  // このとき3つのビルで共通の階数を動かすと2,1,0の値をとりうるので3通り
  // 2つのビルで共通の階数を動かすと4,3,2の値をとりうるので3通り
  // 1つのビルのみが持っている階数を動かすと7,6,5,4の4通り
  // 答えは36通りとなるが、上記の操作はお互いに関係がない
  // 1つの操作に対して他の操作が取りうる全ての状態を考えることができるので
  // 全てかければ良い
  for (int i = 1; i <= N; i++) Q[i] = A[i] - A[i - 1];
  for (int i = 1; i <= N; i++) {
    Answer *= (Q[i] + 1LL);
    Answer %= mod;
  }
  cout << Answer << endl;

  return 0;
}