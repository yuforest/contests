// g++ -o b.out b.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc212/tasks/abc212_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc212/tasks/abc212_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int S, T;
  cin >> S >> T;
  int ans = 0;
  for (int i = 0; i <= 100; ++i) {
    for (int j = 0; j <= 100; ++j) {
      for (int k = 0; k <= 100; ++k) {
        if (i + j + k <= S && i * j * k <= T) ans++;
      }
    }
  }
  cout << ans << endl;
}