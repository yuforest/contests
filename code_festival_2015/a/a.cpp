// g++ -o a.out a.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc217/tasks/abc217_a
// oj t
// oj s https://atcoder.jp/contests/abc217/tasks/abc217_a a.cpp

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
	string S;
  cin >> S;
  long long  black = 0;
  long long  ans = 0;
  for (int i = 0; i < S.size(); ++i) {
    if (S[i] == 'B') black++;
    if (S[i] == 'W') {
      ans += black;
    }
  }
  cout << ans << endl;
}