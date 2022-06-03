// g++ -o a.out a.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc234/tasks/abc234_a
// oj t -c "./a.out"
// oj s https://atcoder.jp/contests/abc234/tasks/abc234_a a.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;

long long func(long long x) {
  return pow(x, 2) + 2 * x + 3;
}

int main(void)
{
  long long t;
  cin >> t;
  long long ans;
  ans = func(func(func(t) + t) + func(func(t)));
  cout << ans << endl;

  return 0;
}