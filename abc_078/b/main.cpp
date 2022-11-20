// g++ -o b.out b.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc226/tasks/abc226_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc226/tasks/abc226_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main()
{
  int X, Y, Z;
  cin >> X >> Y >> Z;
  ll ans = 0;
  while(true) {
    if (X >= Y * (ans+1) + Z * (ans + 1 + 1)) {
      ans++;
    } else {
      break;
    }
  }
  cout << ans << endl;
}