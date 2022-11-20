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

int ans[2010];
int H, W;
vvb used(507, vb(507, false));
string S[507];
int ans_x, ans_y;
void dfs(int x, int y) {
  if (used[x][y]) {
    ans_x = -1;
    ans_y = -1;
    return;
  }
	used[x][y] = true;

  char current = S[x][y];

  if (current == 'U' && x != 0) {
    dfs(x-1, y);
  } else if (current == 'D' && x != H-1) {
    dfs(x+1, y);
  } else if (current == 'L' && y != 0) {
    dfs(x, y-1);
  } else if (current == 'R' && y != W-1) {
    dfs(x, y+1);
  } else {
    ans_x = x;
    ans_y = y;
    return;
  }
}

const double PI = acos(-1.0);
double angle(double y, double x) {
  return atan2(y, x) * 180 / PI;
}


double x[4], y[4];
double get_angle(int pos) {
  int a_pos, b_pos;
  if (pos == 3) {
    a_pos = 0;
  } else {
    a_pos = pos + 1;
  }
  if (pos == 0) {
    b_pos = 3;
  } else {
    b_pos = pos - 1;
  }
  double a_x = (x[a_pos] - x[pos]);
  double a_y = (y[a_pos] - y[pos]);
  double b_x = (x[b_pos] - x[pos]);
  double b_y = (y[b_pos] - y[pos]);
  double cos1 = (a_x * b_x + a_y * b_y) / (sqrt(a_x * a_x + a_y * a_y) * sqrt(b_x * b_x + b_y * b_y));
  debug(cos1);
  debug(acos(cos1));
  double angle = acos(cos1) * 180 / PI;
  debug(angle);
  return angle;
}


int main() {

  rep(i, 4) {
    cin >> x[i] >> y[i];
  }

  bool ans = true;
  double angle_a = get_angle(0);
  double angle_b = get_angle(1);
  double angle_c = get_angle(2);
  double angle_d = get_angle(3);
  double all = 360;
  if (all - angle_a - angle_b - angle_c - angle_d > EPS) ans = false;
  // if (angle_a >= 180) ans = false;
  // if (angle_b >= 180) ans = false;
  // if (angle_c >= 180) ans = false;
  // if (angle_d >= 180) ans = false;

  if (ans) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}