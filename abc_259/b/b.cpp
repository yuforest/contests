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
  const double PI = acos(-1.0);

  double a, b, d;
  cin >> a >> b >> d;

  double angle = d * PI / 180;
  double a_minus, b_minus;
  a_minus = a * cos(angle) - b * sin(angle);
  b_minus = a * sin(angle) + b * cos(angle);
  cout << fixed << setprecision(16);
  cout << a_minus << " " << b_minus << endl;
}