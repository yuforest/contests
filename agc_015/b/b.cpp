// g++ -o b.out b.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc226/tasks/abc226_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc226/tasks/abc226_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main()
{
  string S;
  cin >> S;
  ll ans = 0;
  ll N = S.size();
  for (int i = 0; i < N; i++) {
    if (i == 0 || i == N-1) {
      ans += N - 1;
    } else {
      if (S[i] == 'U') {
        ans += N - i - 1;
        ans += 2 * i;
      } else {
        ans += i;
        ans += 2 * (N - i - 1);
      }
    }
  }
  cout << ans << endl;
}