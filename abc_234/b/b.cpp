// g++ -o b.out b.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc233/tasks/abc233_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc233/tasks/abc233_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main()
{
  int N;
  cin >> N;
  int x[N+1];
  int y[N+1];
  rep1 (i, N) {
    cin >> x[i] >> y[i];
  }
  double ans = 0;
	for (int i = 1; i <= N; i++) {
    for (int j = i+1; j <= N; j++) {
      int x_diff = (x[i] - x[j]);
      int y_diff = (y[i] - y[j]);
      ans = max(ans, sqrt(x_diff * x_diff + y_diff * y_diff));
    }
  }
  cout << setprecision(15) << ans << endl;
}