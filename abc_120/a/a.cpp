// g++ -o a.out a.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc233/tasks/abc233_a
// oj t -c "./a.out"
// oj s https://atcoder.jp/contests/abc233/tasks/abc233_a a.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;

int main(void)
{
  int X, Y;
  cin >> X >> Y;
  if (Y - X < 0) {
    cout << 0 << endl;
  } else {
    cout << ceil((Y - X) / 10.0) << endl;
  }

  return 0;
}