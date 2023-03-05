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
using vvvl = vector<vector<vector<ll>>>;
using pii = pair<int, int>;

long long mod = 1000000007;
// vector<ll> G[1 << 18];

// ACLです。使わない時はコメントアウトしています。導入方法はググってみてください。
#include <atcoder/all>
using namespace atcoder;

// 競プロerはrepマクロが大好き
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep3(i,a,b) for(int i=a;i<b;i++)
#define per(i, b) per2(i, 0, b)
#define per3(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
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

// bool closed = false;
// int cnt = 0;
// map<string, bool> visited;
// map<string, vector<string>> mp;

// void dfs(string cur) {
//   visited[cur] = true;
//   for(auto x: mp[cur]) {
//     // 訪問済み頂点に訪れたらダメ
//     if (visited[x]) {
//       closed = true;
//       return;
//     }
//     cnt++;
//     dfs(x);
//   }
// }

// int main() {
//   ll N;
//   cin >> N;
//   vs S(N), T(N);
//   rep(i, N) {
//     cin >> S[i] >> T[i];
//     mp[S[i]].push_back(T[i]);
//   }
//   debug(mp);
//   vs candidates;
//   map<string, ll> s_cnt;
//   map<string, ll> t_cnt;
//   rep(i, N) {
//     s_cnt[S[i]]++;
//     t_cnt[T[i]]++;
//   }
//   for (auto x: t_cnt) {
//     if (x.second != 1) {
//       cout << "No" << endl;
//       return 0;
//     }
//   }
//   for (auto x: s_cnt) {
//     if (x.second != 1) {
//       cout << "No" << endl;
//       return 0;
//     }
//   }
//   rep(i, N) {
//     if (t_cnt[S[i]] == 0) candidates.push_back(S[i]);
//   }
//   debug(candidates);
//   if (candidates.size() == 0) {
//     cout << "No" << endl;
//     return 0;
//   }
//   rep(i, candidates.size()) {
//     dfs(candidates[i]);
//   }
//   debug(cnt);
//   if (!closed && cnt == N) {
//     cout << "Yes" << endl;
//   } else {
//     cout << "No" << endl;
//   }
//   return 0;
// }

// // 4
// // a b
// // b c
// // c a
// // d e

// // 3
// // b m
// // m d
// // d b

int main(){
  int n;
  cin >> n;
  dsu d(2*n);

  int size=0;
  // 文字毎にindexを保存するmap
  map<string, int> idx;

  for(int i=0;i<n;i++){
    string S,T;
    cin >> S >> T;
    // 見つからなければindexをインクリメントして作ってインクリメントする
    if(idx.find(S) == idx.end())idx[S]=size++;
    if(idx.find(T) == idx.end())idx[T]=size++;
    // SとTが同じ連結成分に属している時実現不可能
    // このときサイクルがあるということ
    if(d.same(idx[S],idx[T])){
      cout << "No" << endl;
      return 0;
    }
    // マージしておく
    d.merge(idx[S],idx[T]);
  }
  // 全部問題なければ構築可能
  cout << "Yes" << endl;
}