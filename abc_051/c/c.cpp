// g++ -o a.out a.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc222/tasks/abc222_a
// oj t -c "./a.out"
// oj s https://atcoder.jp/contests/abc222/tasks/abc222_a c.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;

int main(void)
{
  int sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;
  string ans = "";
  for (int i = sy; i < ty; i++) {
    ans += "U";
  }
  for (int i = sx; i < tx; i++) {
    ans += "R";
  }
  for (int i = sy; i < ty; i++) {
    ans += "D";
  }
  for (int i = sx; i < tx; i++) {
    ans += "L";
  }
  ans += "L";
  for (int i = sy; i < ty+1; i++) {
    ans += "U";
  }
  for (int i = sx; i < tx+1; i++) {
    ans += "R";
  }
  ans += "D";
  ans += "R";
  for (int i = sy; i < ty+1; i++) {
    ans += "D";
  }
  for (int i = sx; i < tx+1; i++) {
    ans += "L";
  }
  ans += "U";
  cout << ans << endl;
}