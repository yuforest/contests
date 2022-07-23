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
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main(void)
{
  int N;
  cin >> N;
  vector<int> S(N);
  int ans = 0;
  rep(i, N) {
    cin >> S[i];
    ans += S[i];
  }
  sort(S.begin(), S.end(), greater<int>());
  if (ans % 10 == 0) {
    for (int i = N-1; i >= 0; i--) {
      if (S[i] % 10 != 0) {
        cout << ans - S[i] << endl;
        return 0;
      }
    }
    cout << 0 << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}