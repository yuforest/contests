// g++ -o b.out b.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc212/tasks/abc212_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc212/tasks/abc212_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  string password;
  cin >> password;
  int X1, X2, X3, X4;
  X1 = password.at(0) - '0';
  X2 = password.at(1) - '0';
  X3 = password.at(2) - '0';
  X4 = password.at(3) - '0';
  // cout << X1 << " " << X2 << " " << X3 << X4;
  if (X1 == X2 && X2 == X3 && X3 == X4) {
    cout << "Weak" << endl;
    return 0;
  }
  if ((X1 + 1) % 10 == X2 && (X2 + 1) % 10 == X3 && (X3 + 1) % 10 == X4) {
    cout << "Weak" << endl;
    return 0;
  }
  cout << "Strong" << endl;

}