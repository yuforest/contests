// g++ -o a.out a.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc219/tasks/abc219_a
// oj t
// oj s https://atcoder.jp/contests/abc219/tasks/abc219_a a.cpp

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int X;
  cin >> X;
  if (X < 40) {
    cout << 40 - X << endl;
  } else if (X < 70) {
    cout << 70 - X << endl;
  } else if (X < 90) {
    cout << 90 - X << endl;
  } else {
    cout << "expert" << endl;
  }
}