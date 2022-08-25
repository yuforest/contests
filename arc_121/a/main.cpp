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


int main(){
  int N;
  cin >> N;
  vector<vector<int>> a;
  set<int> ids;
  for (int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    a.emplace_back(vector<int>{x, y, i});
  }
  for (int k = 0; k < 2; k++) {
    // 昇順ソート(xとyでそれぞれ行う)
    sort(a.begin(), a.end());
    for (int i = 0; i < 2; i++) {
      // 最小から2つのインデックス
      ids.emplace(a[i][2]);
      // 最大から2つのインデックス
      ids.emplace(a[N - 1 - i][2]);
    }
    // xとyの値入れ替え
    for (auto &v : a)
      swap(v[0], v[1]);
  }

  vector<pair<int, int>> b;
  // idsに追加したインデックスにあればx座標とy座標のペアをbに追加
  for (auto v : a)
    if (ids.count(v[2]) != 0)
      b.emplace_back(v[0], v[1]);
  // 全探索で距離を求める
  vector<ll> d;
  for (int i = 0; i < b.size(); i++)
    for (int j = i + 1; j < b.size(); j++)
      d.emplace_back(max(abs(b[i].first - b[j].first), abs(b[i].second - b[j].second)));

  sort(d.begin(), d.end());
  cout << d[d.size() - 2] << endl;
}
