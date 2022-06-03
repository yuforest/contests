// g++ -o b.out b.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc226/tasks/abc226_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc226/tasks/abc226_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main()
{
  int foods[5];
  rep(i, 5) {
    cin >> foods[i];
  }
  int last_digit_min = foods[0];
  rep (i, 5) {
    int last_digit = foods[i] % 10;
    if (last_digit != 0 && last_digit < last_digit_min % 10) {
      last_digit_min = foods[i];
    }
  }
  int ans = 0;
  bool used = false;
  rep(i, 5) {
    if (!used && last_digit_min == foods[i]) {
      used = true;
      continue;
    }
    ans += ceil(foods[i] / 10.0) * 10;
  }
  ans += last_digit_min;
  cout << ans << endl;
}