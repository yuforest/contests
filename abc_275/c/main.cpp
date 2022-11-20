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
const ll INF = ll(1e18);

void recursive_comb(int *indexes, int s, int rest, std::function<void(int *)> f) {
  if (rest == 0) {
    f(indexes);
  } else {
    if (s < 0) return;
    recursive_comb(indexes, s - 1, rest, f);
    indexes[rest - 1] = s;
    recursive_comb(indexes, s - 1, rest - 1, f);
  }
}

// nCkの組み合わせに対して処理を実行する
void foreach_comb(int n, int k, std::function<void(int *)> f) {
  int indexes[k];
  recursive_comb(indexes, n - 1, k, f);
}

int main() {
  string S[9];
  rep(i, 9) cin >> S[i];
  vector<pair<int, int>> porns;
  rep(i, 9) {
    rep(j, 9) {
      if (S[i][j] == '#') porns.push_back({i, j});
    }
  }
  debug(porns);
  ll N = porns.size();
  // 80^2 = 6400
  ll ans = 0;
  set<vector<pair<int, int>>> vals;
  foreach_comb(N, 2, [porns, S, &vals](int *indexes) {
    ll first = indexes[0];
    ll second = indexes[1];
    ll x = porns[second].first - porns[first].first;
    ll y = porns[first].second - porns[second].second;
    ll x1 = porns[first].first + y;
    ll y1 = porns[first].second + x;
    ll x2 = porns[second].first + y;
    ll y2 = porns[second].second + x;
    if ((0 <= x1 && x1 <= 8) && (0 <= y1 && y1 <= 8) && S[x1][y1] == '#') {
      if ((0 <= x2 && x2 <= 8) && (0 <= y2 && y2 <= 8) && S[x2][y2] == '#') {
        vector<pair<int, int>> val= {
          {porns[first].first, porns[first].second},
          {porns[second].first, porns[second].second},
          {x1, y1},
          {x2, y2}
        };
        sort(val.begin(),val.end());
        vals.insert(val);
      }
    }
  });
  debug(vals);
  ans = vals.size();
  cout << ans << endl;
}