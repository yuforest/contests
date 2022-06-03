// g++ -o c.out c.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc216/tasks/abc216_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc216/tasks/abc216_c c.cpp

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;

int main(void)
{
  long long X, K, D;
  cin >> X >> K >> D;
  X = abs(X);

  ll straight = min(K, X / D);
  K -= straight;
  X -= straight * D;

  if (K % 2 == 0) {
    cout << X << endl;
  } else {
    cout << D - X << endl;
  }
}