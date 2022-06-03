// g++ -o c.out c.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc233/tasks/abc233_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc233/tasks/abc233_c c.cpp

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
map<int, int> mp;

int main(){
  int N, X;
  cin >> N >> X;
  int a[N+1], b[N+1];
  vector<vector<bool>> dp(N+1, vector<bool>(X+1, false));
  dp[0][0] = true;
  rep1(i, N) {
    cin >> a[i] >> b[i];
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= X; j++) {
      if (j-a[i] >= 0 && j-a[i] <= X && dp[i-1][j-a[i]] == true) {
        dp[i][j] = true;
      }
      if (j-b[i] >= 0 && j-b[i] <= X && dp[i-1][j-b[i]] == true) {
        dp[i][j] = true;
      }
    }
  }
  if (dp[N][X]) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}