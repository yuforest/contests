// g++ -o a.out a.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc216/tasks/abc216_a
// oj t
// oj s https://atcoder.jp/contests/abc216/tasks/abc216_a a.cpp

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int A[21];
  A[0] = 100;
  A[1] = 100;
  A[2] = 200;
  for (int i = 0; i < 20; i++) {
    if (i < 3) continue;
    A[i] = A[i-1] + A[i-2] + A[i-3];
  }
  cout << A[19] << endl;
}