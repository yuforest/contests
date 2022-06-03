// g++ -o c.out c.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc216/tasks/abc216_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc216/tasks/abc216_c c.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;

int main(void)
{
  long long N;
  cin >> N;
  string ans = "";
  while (true) {
    if (N / 2 < 1) {
      ans += "A";
      break;
    }
    if (N % 2 == 0) {
      N /= 2;
      ans += "B";
    } else {
      N -= 1;
      ans += "A";
    }
  }
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
}