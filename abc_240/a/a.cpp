// g++ -o a.out a.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc235/tasks/abc235_a
// oj t -c "./a.out"
// oj s https://atcoder.jp/contests/abc235/tasks/abc235_a a.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;

int main(void)
{
  int a, b;
  cin >> a >> b;
  if (a == 1 && b == 10 || a == 10 && b == 1) {
    cout << "Yes" << endl;
  } else if (a + 1 == b || b + 1 == a) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}