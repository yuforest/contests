// g++ -o a.out a.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc256/tasks/abc256_a
// oj t -c "./a.out"
// oj s https://atcoder.jp/contests/abc256/tasks/abc256_a a.cpp

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;
using ll = long long;

int main(void)
{
  int K;
  cin >> K;
  int hour;
  int minute;
  string ans = "";
  if (K>=60) {
    hour = 22;
  } else {
    hour = 21;
  }
  ans += to_string(hour);
  ans += ":";
  if (K % 60 < 10) {
    ans += "0";
  }
  minute = K % 60;
  ans += to_string(minute);
  cout << ans << endl;
}