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
  ll A, B, C, K;
  cin >> A >> B >> C >> K;
  int ans;
  if (K % 2 == 1) {
    ans = B - A;
  } else {
    ans = A - B;
  }
  cout << ans << endl;
}