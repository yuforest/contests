// g++ -o a.out a.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc213/tasks/abc213_a
// oj t
// oj s https://atcoder.jp/contests/abc213/tasks/abc212_a a.cpp

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int m, n, N;
  cin >> m >> n >> N;
  int sum = N, short_count = N, remain = 0;
  int count = 0;
  while (true) {
    short_count += remain;
    remain = 0;
    if (short_count < m || count > 5) break;
    remain = short_count % m;
    short_count = short_count / m * n;
    sum += short_count;
  }
  cout << sum << endl;
}