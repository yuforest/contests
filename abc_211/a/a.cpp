// g++ -o a.out a.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc210/tasks/abc211_a
// oj t
// oj s https://atcoder.jp/contests/abc210/tasks/abc211_a a.cpp

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int A, B;
  cin >> A >> B;
  double C;
  C = (A - B) / 3.0 + B;
  cout << fixed << setprecision(7) << C << endl;
}