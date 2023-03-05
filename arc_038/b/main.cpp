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

const int MX = 105;

int H, W;
string S[MX];

// 駒の位置と勝敗を記録するmap、最初は未定
map<pair<int,int>,bool> mem;
// (i, j)に駒がある状態か開始した時の勝敗
// 勝敗が確定していくのは後ろの状態なので後ろから探索していることになる
// 2 3
// .#.
// ...
// 例えば上の盤面でmemには((1, 2), 0)が入るがこれはここからゲームを始めると
// 後手が必ず勝つということ
// なぜなら先手はここから駒を動かせないから
// 1,2から探索をすると再帰的に呼び出されるjudge関数はいずれもtrueを返す
// するとresの値は変わらないのでmem[(1,2)]はfalseとなる
// このようにして最終局面から勝敗を決定していく
// 次に(1,1)からゲームを始めた場合を考える
// このとき再帰的に呼び出されるjudgeで下や右下に対する呼び出しはtrueを返すが
// 右に対する呼び出しはfalseを返す
// よってresはtrueになり、mem[(1,1)]はtrueとなる、このとき先手必勝となる
// 次に(1,0)からゲームを始めた場合を考えてみる
// このとき再帰的に呼び出されるjudgeで下や右下に対する呼び出しは盤面外のためtrueを返すが
// 右に対する呼び出しもtrueを返す
// よってresはfalseとなり
// mem[(1,0)]はfalseとなる
// 最後に(0,0)からゲームを始めた場合を考えてみる
// このとき再帰的に呼び出されるjudgeで右に対する呼び出しは障害物のためtrue
// 下に対する呼び出しはfalse、右下に対する呼び出しはtrueを返す
// falseなものがあるので、resはtrueになりmem[(0,0)]はtrueになる

// 盤面外や障害物に当たってtrueを返すとき、
// その一つ上の呼び出し元でない方が勝つということになる
// つまり一つ上の呼び出し元が全てtrueになってしまえば動かすことができずに
// 呼び出し元のプレイヤーが負ける、よって負けを入れる
// そしてその更に上の呼び出し元から考えた時に、負けの状態に遷移することができれば
// 自分は勝つことができる、よって再帰的な呼び出しで一つでもfalseになるものがあれば
// そこは勝ちの状態となる
// もうさらに上まで考えると、全ての遷移先が盤面外か勝ちの状態である時
// 自分のターンで勝ちの状態に遷移してしまうと、相手を勝たせてしまうことになる
// よってそのマス目は負けの状態となる
bool judge(int i, int j) {
  // 盤面外や障害物に当たったらtrueを返す
  if (i >= H || j >= W || S[i][j] == '#') return true;
  // 値が既に入っていればそれを返す
  if (mem.count({i,j})) return mem[{i,j}];
  bool res = false;
  // 下記の移動方法のうち一つでもfalseなものがあればresはtrueになる
  // 右
  res |= !judge(i,j+1);
  // 下
  res |= !judge(i+1,j);
  // 右下
  res |= !judge(i+1,j+1);
  return mem[{i,j}] = res;
}

int main() {
  // 入力を受け取る
  cin >> H >> W;
  for (int i = 0; i < H; ++i) cin >> S[i];

  // (0,0)からメモ化再帰、trueなら先手が勝つ、falseなら後手が勝つ
  cout << (judge(0,0) ? "First" : "Second") << endl;
  debug(mem);
  return 0;
}