// g++ -o a.out a.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc222/tasks/abc222_a
// oj t -c "./a.out"
// oj s https://atcoder.jp/contests/abc222/tasks/abc222_a c.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()

// DPやlong longの最大値最小値更新で重宝します。
template <typename T>
inline bool chmax(T &a, T b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T>
inline bool chmin(T &a, T b) {
  return ((a > b) ? (a = b, true) : (false));
}

int main(void)
{
  int N, K;
  cin >> N >> K;
  int x[N];
  rep(i, N) {
    cin >> x[i];
  }
  vector<int> mi, pr;
  mi.push_back(0);
  pr.push_back(0);
  rep(i, N) {
    if (x[i] <= 0) mi.push_back(-x[i]);
    else pr.push_back(x[i]);
  }
  sort(all(mi));
  sort(all(pr));

  int n = mi.size();
  int m = pr.size();
  int ans = INT_MAX;
  // どれだけ負に行くかであるが、
  // 負のろうそくをi個経由した場合は正のろうそくをK-i個通る必要がある
  // iを固定するとO(1)で必要な移動量がわかるので、iを全探索すればいい

  // i回マイナス方向に行ってからK-i回プラス方向に行くのを全探索
  rep(i, n) {
    int j = K - i;
    if (0 <= j && j < m) chmin(ans, mi[i] * 2 + pr[j]);
  }
  // i回プラス方向に行ってからK-i回マイナス方向に行くのを全探索
  rep(i, m) {
    int j = K - i;
    if (0 <= j && j < n) chmin(ans, pr[i] * 2 + mi[j]);
  }
  cout << ans << endl;
}