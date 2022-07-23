// g++ -o a.out a.cpp -std=c++17
// oj d https://atcoder.jp/contests/agc_012/tasks/agc_012_a
// oj t -c "./a.out"
// oj s https://atcoder.jp/contests/agc_012/tasks/agc_012_a a.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main(void)
{
  ll N;
  cin >> N;
  vector<ll> A(N);
  vector<ll> B(N);
  rep(i, N) {
    cin >> A[i] >> B[i];
  }
  reverse(A.begin(), A.end());
  reverse(B.begin(), B.end());
  ll ans = 0;
  rep(i, N) {
    ll val = A[i] + ans;
    if (val % B[i] == 0) continue;
    ll tmp = B[i] - (val % B[i]);
    ans += tmp;
  }
  cout << ans << endl;
}