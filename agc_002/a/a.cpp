// g++ -o a.out a.cpp -std=c++11
// oj d https://atcoder.jp/contests/agc003/tasks/agc003_a
// oj t
// oj s https://atcoder.jp/contests/agc003/tasks/agc003_a a.cpp

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int a, b;
  cin >> a >> b;
  if ((a < 0 && b > 0) || (a > 0 && b < 0) || a == 0 || b == 0) {
    cout << "Zero" << endl;
  } else if ((a > 0 && b > 0) || (abs(a) - abs(b) + 1) % 2 == 0) {
    cout << "Positive" << endl;
  } else {
    cout << "Negative" << endl;
  }
}