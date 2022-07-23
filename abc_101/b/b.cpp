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

  int D, N;
  cin >> D >> N;
  int ans;
  if (D==0) {
    if (N == 100) {
      ans = 1 * (N + 1);
    } else {
      ans = 1 * N;
    }
  } else if (D == 1) {
    if (N == 100) {
      ans = 100 * (N + 1);
    } else {
      ans = 100 * N;
    }
  } else {
    if (N == 100) {
      ans = 10000 * (N + 1);
    } else {
      ans = 10000 * N;
    }
  }
  cout << ans << endl;

}