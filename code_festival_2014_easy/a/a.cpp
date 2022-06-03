// g++ -o a.out a.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc217/tasks/abc217_a
// oj t
// oj s https://atcoder.jp/contests/abc217/tasks/abc217_a a.cpp

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
	int N;
  cin >> N;
  long long A[N];
  rep (i, N) {
    cin >> A[i];
  }
  double ans = 0;
  rep (i, N-1) {
    ans += A[i+1] - A[i];
  }
  ans /= (N - 1) * 1.0;
  cout << setprecision(15) << ans << endl;
}