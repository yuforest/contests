// g++ -o d.out d.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc222/tasks/abc222_d
// oj t -c "./d.out"
// oj s https://atcoder.jp/contests/abc222/tasks/abc222_d d.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
// long long mod = 1000000007;
// 縦軸が弁当の種類、横軸がたこ焼きの数、配列の値が鯛焼きの数
int dp[301][301][301];

int main(void)
{
  int N;
  int mod = 998244353;
  cin >> N;
  int A[N];
  int B[N];
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> B[i];
  }
  long long dp[3001][3001];
  for (int i = 0; i < 3001; i++) {
    for (int j = 0; j < 3001; j++) {
      dp[i][j] = 0;
    }
  }
  for (int i = 0; i < N; i++) {
    if (i == 0) {
      for (int j = A[i]; j <= B[i]; j++) {
        dp[i][j] = 1;
      }
    } else {
      int current_a = A[i];
      int current_b = B[i];
      for (int j = 0; j < 3001; j++) {
        if (dp[i-1][j] == 0) continue;
        if(dp[i-1][j] >= current_a && dp[i-1][j] <= current_b) {
          dp[i][j] += 1;
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i <= 3000; i++) {
    ans += dp[N][i];
  }
  cout << ans % mod << endl;
  cout << "hello" << endl;
}