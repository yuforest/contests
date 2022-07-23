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
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main(void)
{
  int N;
  cin >> N;
  int P[N+1];
  rep(i, N) {
    cin >> P[i];
  }
  int ans = 0;
  rep(i, N) {
    if (i+1 == P[i]) {
      int tmp = P[i];
      P[i] = P[i+1];
      P[i+1] = tmp;
      ans++;
    }
  }
  cout << ans << endl;
}