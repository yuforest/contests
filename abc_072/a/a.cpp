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
  double I;
  cin >> I;
  int X;
  int Y;
  X = floor(I);
  Y = I * 10 - X * 10;
  if (Y >= 0 && Y <= 2) {
    cout << X << "-" << endl;
  } else if (Y >= 3 && Y <= 6) {
    cout << X << endl;
  } else if (Y >= 7 && Y <= 9) {
    cout << X << "+" << endl;
  }
}