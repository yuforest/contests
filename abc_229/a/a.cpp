// g++ -o a.out a.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc229/tasks/abc229_a
// oj t -c "./a.out"
// oj s https://atcoder.jp/contests/abc229/tasks/abc229_a a.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;

int main(void)
{
  string S1, S2;
  cin >> S1 >> S2;
  bool ans = true;
  if (S1[0] == '#' && S2[1] == '#') {
    if (S1[1] == '.' && S2[0] == '.') {
      ans = false;
    }
  }
  if (S1[1] == '#' && S2[0] == '#') {
    if (S1[0] == '.' && S2[1] == '.') {
      ans = false;
    }
  }

  if (ans) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}