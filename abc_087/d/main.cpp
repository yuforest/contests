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


int N, M;
vector<pair<int, int>> E[201010];
vector<pair<int, int>> EE[201010];
int vis[201010], col[201010];

#define no "No"
#define yes "Yes"


// 1つ数を決めるとそれと連結の座標の数が全て決まる
string solve() {
  // 0からNまでの頂点を全て訪れる
  rep(i, N) if (!vis[i]) {
    // 訪問済みでないとき下記を実行
    // 座標のまだ数が決まってない所の1つを0に
    col[i] = 0;
    // 訪問済みにする
    vis[i] = 1;
    queue<int> que;
    que.push(i);
    // 幅優先探索
    // 例えば、1から2に辺を張っているとき、
    // 1から2に向かう距離は1
    // 2から1に向かう距離は-1
    while (!que.empty()) {
      int q = que.front(); que.pop();
      debug(q);

      // 右にある頂点でqからの相対位置が確定しているもの
      fore(p, E[q]) {
        // 矛盾したらNo
        if (vis[p.first]) {
          if (col[q] + p.second != col[p.first]) return no;
        } else {
          // 距離を確定させる
          col[p.first] = col[q] + p.second;
          // 訪問済みにする
          vis[p.first] = 1;
          // 次の探索候補に追加
          que.push(p.first);
        }
      }

      // 左にある頂点でqからの相対位置が確定しているもの
      fore(p, EE[q]) {
        // 矛盾したらNo
        if (vis[p.first]) {
          if (col[q] - p.second != col[p.first]) return no;
        }
        else {
          // 距離を確定させる
          col[p.first] = col[q] - p.second;
          // 訪問済みにする
          vis[p.first] = 1;
          // 次の探索候補に追加
          que.push(p.first);
        }
      }
    }
  }
  return yes;
}

int main() {
  cin >> N >> M;
  rep(i, M) {
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    // aからbに辺を張る
    E[a].push_back({ b, c });
    // bからaに辺を張る
    EE[b].push_back({ a, c });
  }
  cout << solve() << endl;
}