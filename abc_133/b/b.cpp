// g++ -o b.out b.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc233/tasks/abc233_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc233/tasks/abc233_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main()
{
  int N, D;
  cin >> N >> D;
  int X[N][D];
  rep(i, N) {
    rep (j, D) {
      cin >> X[i][j];
    }
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i+1; j < N; j++) {
      double distance = 0;
      for (int k = 0; k < D; k++) {
        distance += pow(X[i][k] - X[j][k], 2.0);
      }
      distance = sqrt(distance);
      if (distance == floor(distance)) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}