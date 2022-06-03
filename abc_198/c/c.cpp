// g++ -o c.out c.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc213/tasks/abc213_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc213/tasks/abc213_c c.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;

int main(void)
{
  int R, X, Y;
  cin >> R >> X >> Y;
  double distance = sqrt(pow(X, 2) + pow(Y, 2));
  int ans;
  if (distance == R * 1.0) {
    cout << 1 << endl;
  } else if (distance <= R * 2.0) {
    cout << 2 << endl;
  } else {
    cout << ceil(distance / R) << endl;
  }
}