// g++ -o b.out b.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc233/tasks/abc233_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc233/tasks/abc233_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main()
{
  long long X;
  cin >> X;
  if (X < 0) {
    if (X % 10 == 0) {
      cout << X / 10 << endl;
    } else {
      cout << X / 10 - 1 << endl;
    }
  } else {
    cout << X / 10 << endl;
  }
}