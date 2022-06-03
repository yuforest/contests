// g++ -o b.out b.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc216/tasks/abc216_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc216/tasks/abc216_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N;
  string S;
  cin >> N >> S;
  int ans = 0;
  for (int i = 0; i < N; ++i) {
      int c1 = 0, c2 = 0;
      for (int j = i; j < N; ++j) {
        if (S[j] == 'A')
            c1++;
        else if (S[j] == 'T')
            c1--;
        else if (S[j] == 'C')
            c2++;
        else
            c2--;
        if (c1 == 0 && c2 == 0) ans++;
      }
  }
  cout << ans << endl;

  return 0;
}
