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


int N, A, B, C, L[10];
int ans = INT_MAX;
// A,B,Cの中でどの長さで使っているかを保存する配列
int flag[8];

void dfs(int cu) {
  // 最後の竹まで見たらMP計算
  if (cu == N) {
    int a = 0, b = 0, c = 0;
    int ca = 0, cb = 0, cc = 0;
    // 長さと使っている竹の本数を計算
    rep3(i, 0, N) {
      if (flag[i] == 0) a += L[i], ca++;
      else if (flag[i] == 1) b += L[i], cb++;
      else if (flag[i] == 2) c += L[i], cc++;
    }
    // 使っている竹が0本の場合はreturn
    if (0 == ca or 0 == cb or 0 == cc) return;
    // 合成魔法のコストを計算
    int cand = (ca-1) * 10 + (cb-1) * 10 + (cc-1) * 10;
    // 延長または短縮のコストを計算
    cand += abs(A - a) + abs(B - b) + abs(C - c);
    // 最小値の更新
    chmin(ans, cand);
    return;
  }

  // 竹をA,B,Cの中でどれに振り分けるかで全探索
  // 0->A, 1->B. 2->C, 3->使わないとして振り分けている
  rep3(i, 0, 4) {
    flag[cu] = i;
    dfs(cu + 1);
  }
}
int main() {
  cin >> N >> A >> B >> C;
  rep3(i, 0, N) cin >> L[i];

  dfs(0);
  cout << ans << endl;

  return 0;
}