// g++ -o c.out c.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc216/tasks/abc216_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc216/tasks/abc216_c c.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;

int main(void)
{
  double N;
  cin >> N;
  double x0, y0;
  double xn2, yn2;
  cin >> x0 >> y0 >> xn2 >> yn2;
  double center_x = (x0 + xn2) / 2.0;
  double center_y = (y0 + yn2) / 2.0;
  x0 -= center_x;
  y0 -= center_y;
  const double PI = acos(-1.0);
  // 回転角は360/N(度数法)=2pi/N(弧度法)
  double x1 = cos(2 * PI / N) * x0 - sin(2 * PI / N) * y0;
  double y1 = sin(2 * PI / N) * x0 + cos(2 * PI / N) * y0;
  x1 += center_x;
  y1 += center_y;

  cout << fixed << setprecision(12) << x1 << " " << y1 << endl;
}