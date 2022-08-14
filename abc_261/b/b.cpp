// g++ -o b.out b.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc219/tasks/abc219_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc219/tasks/abc219_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int N;
  cin >> N;
  string A[N];
  rep(i, N) {
    cin >> A[i];
  }
  string ans = "correct";
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      if (i == j) continue;
      if (A[i][j] == 'W' && A[j][i] != 'L') ans = "incorrect";
      if (A[i][j] == 'L' && A[j][i] != 'W') ans = "incorrect";
      if (A[i][j] == 'D' && A[j][i] != 'D') ans = "incorrect";
    }
  }
  cout << ans << endl;
}