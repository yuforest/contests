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

int main() {
  int N, M;
  cin >> N >> M;
  vl A(M), B(M);
  dsu uf(N);
  rep(i, M) {
    cin >> A[i] >> B[i];
    A[i]--;
    B[i]--;
    // 小さい方から大きい方に張る辺だけで良い
    // 頂点を小さい方から削除していくため、
    // 大きい方から小さい方に張る辺は意味がない
    G[A[i]].push_back(B[i]);
  }
  vl ans;
  ans.push_back(0);
  // 最初連結成分の数は0、頂点がない状態
  ll tmp = 0;
  for(ll i=N-1; i>=1; i--) {
    // 頂点iを追加、頂点を増やしていく
    tmp++;
    // この中身は全て合わしても200000程度なので、O(N*M)にはならず、
    // 定数倍ということになり、O(N)で解ける
    for(auto x: G[i]) {
      if (!uf.same(i, x)) {
        uf.merge(i, x);
        // 非連結の頂点同士をつなげたとき、連結成分の数は1減る
        // 例えば3と5,6が連結の時に連結成分の数は2減ることになる
        tmp--;
      }
    }
    // uf.groups()は計算量がNになるので安易に使うとTLEする
    ans.push_back(tmp);
  }
  reverse(ans.begin(),ans.end());
  rep(i, ans.size()) {
    cout << ans[i] << endl;
  }


}