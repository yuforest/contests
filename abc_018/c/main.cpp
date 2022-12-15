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
int N, M;

int main() {
  int R, C, K;
  cin >> R >> C >> K;
  bool isBlocked[500][500] = {{ false }};
  for (int i = 0; i < R; i++){
    string s;
    cin >> s;
    for (int j = 0; j < C; j++){
      // 黒いマスであれば
      // xを中心として中心からの距離がK-1以下の菱形の部分は使えないようにする
      // その距離の範囲内にあるところから菱形と作ろうとしても失敗する
      if (s.at(j) == 'x'){
        // xとyの取りうる範囲を探索
        // 長方形領域を探索して条件部分で絞っている
        // xからの距離がK−1以内のマスを探索
        for (int x = i - (K - 1); x <= i + (K - 1); x++){
          for (int y = j - (K - 1); y <= j + (K - 1); y++) {
            // x,yが長方形領域の範囲で、|i-x|+|j-y|<= K-1を満たしている場合ブロックする
            if (x >= 0 && x < R && y >= 0 && y < C && abs(x - i) + abs(y - j) <= K - 1) isBlocked[x][y] = true;
          }
        }
      }
    }
  }

  int ans = 0;
  // x(K<=x<=R-K+1), y(K<=y<=C-K+1)を満たすx,yに対してブロックされていないところを数える
  for (int i = K - 1; i < R - K + 1; i++){
    for (int j = K - 1; j < C - K + 1; j++){
      if (!isBlocked[i][j]) {
        debug(i);
        debug(j);
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}