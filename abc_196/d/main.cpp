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

int H, W, A, B;
//---------------------------------------------------------------------------------------------------
// 316=43046721なので4*106通りで間に合うかなという印象、ここから次に遷移できないときなどが枝狩りされる
bool used[16][16];
// 現在見ている座標と長方形のタイルを使える数
int dfs(int x, int y, int a) {
  // 最後まで探索して、長方形のタイルを使い切っているなら、組合せを+1する
  if (H == y) return a == 0;

  // 横の端まで行ったら次の行へ
  if (W == x) return dfs(0, y + 1, a);

  // 既に置かれているなら何もできないので、次のマスへ
  if (used[y][x]) return dfs(x + 1, y, a);

  int res = 0;

  // 縦置き(高さがはみ出していない、下のマスが使用済みでない、長方形が残っている)
  if (y + 1 < H && !used[y + 1][x] && 0 < a) {
    // 現在のマスとその下のマスに配置
    used[y][x] = used[y + 1][x] = true;
    // 横に遷移していく
    res += dfs(x + 1, y, a - 1);
    used[y][x] = used[y + 1][x] = false;
  }

  // 横置き(幅がはみ出していない、右のマスが使用済みでない、長方形が残っている)
  if (x + 1 < W && !used[y][x + 1] && 0 < a) {
    // 現在のマスとその右のマスに配置
    used[y][x] = used[y][x + 1] = true;
    // 横に遷移していく
    res += dfs(x + 1, y, a - 1);
    used[y][x] = used[y][x + 1] = false;
  }

  // 何も置かない
  res += dfs(x + 1, y, a);

  return res;
}
int main(){
  cin >> H >> W >> A >> B;
  cout << dfs(0, 0, A) << endl;
  return 0;
}