// g++ -o a.out a.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc219/tasks/abc219_a
// oj t
// oj s https://atcoder.jp/contests/abc219/tasks/abc219_a a.cpp

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int A, B;
  cin >> A >> B;
  if (A == 1) A += 13;
  if (B == 1) B += 13;

  if (A > B) {
    cout << "Alice" << endl;
  } else if (A < B) {
    cout << "Bob" << endl;
  } else {
    cout << "Draw" << endl;
  }
}