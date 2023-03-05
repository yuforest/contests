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

long long px[300];
long long py[300];
bool flag[300][300];
// aとbを通る直線上にcが乗っているかを確かめる
// AC = kABのベクトルとして表せることと同値
// val1 = val2のとき
// (y2-y1)*(x3-x1) = (x2-x1)(y3-y1)
// (y2-y1)/(x2-x1) = (y3-y1)/(x3-x1)
// つまりこれは点1,点2を通る直線の傾きと点1,点3を通る直線の傾きが等しいかを確かめている
// これが等しい時3点は1つの直線上にある
bool colinear(int a, int b, int c) {
  long long val1 = (py[b] - py[a])*(px[c] - px[a]);
  long long val2 = (px[b] - px[a])*(py[c] - py[a]);
  return (val1 == val2);
}
int main(void) {
  int n, k, cnt, ans;
  vector<int>list;
  cin >> n >> k;
  for (int i = 0; i < n; i++)cin >> px[i] >> py[i];

  if (k == 1) {
    cout << "Infinity" << endl;
    return 0;
  }
  // 2点の組み合わせをtrueに設定しておく
  for (int i = 0; i < n; i++)for (int j = i + 1; j < n; j++)flag[i][j] = true;
  ans = 0;
  // 2点の組み合わせ探索
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      // その組み合わせが存在すれば
      if (flag[i][j]) {
        // 今の直線を通る点の数
        cnt = 2;
        // 空にする
        list.clear();
        list.push_back(i);
        list.push_back(j);
        // それ以降の点でこの直線を通る点をカウントする
        for (int ii = j + 1; ii < n; ii++) {
          if (colinear(i, j, ii)) {
            cnt++;
            list.push_back(ii);
          }
        }
        // 同じ直線をカウントしないようにlistに入っている点は消しておく
        for (int ii = 0; ii < cnt; ii++)for (int jj = ii + 1; jj < cnt; jj++)flag[list[ii]][list[jj]] = false;
        // これがk以上であればカウントする
        if (cnt >= k)ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}