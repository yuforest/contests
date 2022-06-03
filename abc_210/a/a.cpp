// g++ -o a.out a.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc210/tasks/abc210_a
// oj t
// oj s https://atcoder.jp/contests/abc210/tasks/abc210_a a.cpp

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int N, A, X, Y;
  cin >> N >> A >> X >> Y;
  if (N > A) {
    int ans;
    ans = A * X + (N - A) * Y;
    cout << ans << endl;
  } else {
    cout << X * N << endl;
  }
}