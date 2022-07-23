// g++ -o d.out d.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc219/tasks/abc219_d
// oj t -c "./d.out"
// oj s https://atcoder.jp/contests/abc219/tasks/abc219_d d.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;
// 縦軸が弁当の種類、横軸がたこ焼きの数、配列の値が鯛焼きの数
int dp[301][301][301];
vector<int> G[1 << 18];
#define rep(i, n) for (int i = 0; i < (n); ++i)

using ll = long long;


vector<bool> used(3005, false);

bool ans = false;

int s_circle = -1;
int t_circle = -1;

void dfs(int pos) {
	used[pos] = true;
  if (pos == t_circle) ans = true;
	for (int i : G[pos]) {
    if (used[i] == false) dfs(i);
	}
}

int main(void)
{
  int N;
  ll s[2], t[2];

  cin >> N;
  cin >> s[0] >> s[1] >> t[0] >> t[1];

  ll x[N], y[N], r[N];

  rep(i, N) {
    cin >> x[i] >> y[i] >> r[i];
  }

  // s, tがどの円の上にあるの確定
  rep(i, N) {
    if((x[i]-s[0])*(x[i]-s[0]) + (y[i]-s[1])*(y[i]-s[1]) == r[i]*r[i]) {
      s_circle = i;
    }
    if((x[i]-t[0])*(x[i]-t[0]) + (y[i]-t[1])*(y[i]-t[1]) == r[i]*r[i]) {
      t_circle = i;
    }
  }
  // cout << s_circle <<endl;
  // cout << t_circle <<endl;

  for (int i = 0; i < N; i++) {
    for (int j = i+1; j < N; j++) {
      ll d = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
      // 距離が半径の和よりも大きいまたは距離が半径の差よりも小さければcontinue
      if(d > (r[i]+r[j])*(r[i]+r[j]) || d < (r[i]-r[j])*(r[i]-r[j])) continue;
      G[i].push_back(j);
      G[j].push_back(i);
    }
  }
  dfs(s_circle);
  if (ans) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}