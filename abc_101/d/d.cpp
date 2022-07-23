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

int main(void)
{
  int N, X, Y;
  cin >> N >> X >> Y;
  int A[N], B[N];
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
  }

  for (int i = 0; i <= 300; i++) {
    for (int j = 0; j <= 300; j++) {
      for (int k = 0; k <= 300; k++) {
        dp[i][j][k] = 607;
      }
    }
  }
  dp[0][0][0] = 0;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= 300; j++) {
      for (int k = 0; k <= 300; k++) {
        if (dp[i][j][k] == 607) continue;
        int takoyaki = A[i];
        int taiyaki  = B[i];
        int takoyaki_index = min(X, j+takoyaki);
        int taiyaki_index = min(Y, k+taiyaki);
        // cout << takoyaki_index << endl;
        // cout << taiyaki_index << endl;
        // cout << dp[i][j][k] + 1 << endl;
        // cout << dp[i][takoyaki_index][taiyaki_index] << endl;
        // cout << endl;

        dp[i+1][takoyaki_index][taiyaki_index] = min(dp[i][j][k] + 1, dp[i+1][takoyaki_index][taiyaki_index]);
        dp[i+1][j][k] = min(dp[i][j][k], dp[i+1][j][k]);
      }
    }
  }

  for (int j = 0; j <= 300; j++) {
      for (int k = 0; k <= 300; k++) {
        if (dp[N][j][k] == 607) continue;
        // cout << j << " " << k << endl;
        // cout << dp[N][j][k] << endl;
      }
  }

  if (dp[N][X][Y] == 607) {
    cout << -1 << endl;
  } else {
    cout << dp[N][X][Y] << endl;
  }
}