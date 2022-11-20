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


// 盤面を引数に取る
// 空いているスペースに石を落とす
void fall(vector<string> &g) {
  int h = g.size();
  int w = g[0].size();
  // 列ごとにみていく
  for (int j = 0; j < w; j++) {
    // 最後の行
    int k = h - 1;
    // 下からみていく
    for (int i = h - 1; i >= 0; i--) {
      // 今見ている位置が0でなければ今の数字を入れてkをデクリメント
      if (g[i][j] != '0') {
        g[k--][j] = g[i][j];
      }
    }
    // kが余っていれば上に0を詰める
    while (k >= 0) g[k--][j] = '0';
  }
}

// 盤面を調べて消したポイントを返す
int erase(vector<string> &g, int K) {
  int h = g.size();
  int w = g[0].size();
  int sum = 0;
  // 全ての行を上から見る
  for (int i = 0; i < h; i++) {
    int j = 0;
    // 端に到達するまで行を見る
    // 一列に複数の消すべき数字があっても、対応できる
    while (j < w) {
      int k = j;
      // 端に到達せず、数字が同じならjをインクリメント
      while (j < w && g[i][j] == g[i][k]) j++;
      // 同じ数字の連続がKより大きければ、当該箇所を消してポイントを加算
      if (j - k >= K) {
        sum += (j - k) * (g[i][k] - '0');
        // k < jである限り(kがjに追いつくまで)インクリメント
        for (; k < j; k++) g[i][k] = '0';
      }
    }
  }
  return sum;
}

// 盤面といくつ並んだ時に消えるかを引数に取る
int run(vector<string> &g, int K) {
  int res = 0;
  // 消えた数が0になるまで繰り返す
  for (int i = 0;; i++) {
    fall(g);
    int s = erase(g, K);
    // 消えた数が0ならbreak
    if (s == 0) break;
    // 点数を加算
    res += (1 << i) * s;
  }
  return res;
}

int main() {
  int h, w, K;
  cin >> h >> w >> K;
  // 盤面の入力
  vector<string> g(h);
  for (int i = 0; i < h; i++) cin >> g[i];

  int ans = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      auto tmp = g;
      // 調べる位置を消す
      tmp[i][j] = '0';
      // i,jを消した時の点数を調べる
      ans = max(ans, run(tmp, K));
    }
  }
  cout << ans << endl;
}