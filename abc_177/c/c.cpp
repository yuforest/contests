// g++ -o c.out c.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc216/tasks/abc216_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc216/tasks/abc216_c c.cpp

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main(void)
{
  ll N;
  cin >> N;
  ll A[N];
  rep(i, N) {
    cin >> A[i];
  }
  ll cumulative[N];
  cumulative[0] = A[0];
  for(int i = 1; i < N; i++) {
    cumulative[i] = cumulative[i-1] + A[i];
  }

  ll ans = 0;

  for(int i = 0; i < N-1; i++) {
    ans += A[i] * ((cumulative[N-1] - cumulative[i]) % mod);
    // cout << A[i] << endl;
    // cout << (cumulative[N-1] - cumulative[i]) << endl;
    ans %= mod;
  }
  cout << ans << endl;
}