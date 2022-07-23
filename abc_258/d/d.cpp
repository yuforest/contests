// g++ -o c.out c.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc233/tasks/abc233_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc233/tasks/abc233_c c.cpp


#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using ll = long long;
const ll LINF = 1e18;
int main() {
  ll N, X;
  cin >> N >> X;
  ll A[N];
  ll B[N];
  rep(i, N) {
    cin >> A[i] >> B[i];
  }

  ll ans = numeric_limits<long long>::max();
  ll sum = 0;
  for (ll i = 0; i < N; i++) {
    if (i+1 > X) break;
    sum += A[i] + B[i];
    ll play = (X-i-1LL);
    ans = min(ans, sum + (B[i] * play));
  }
  cout << ans << endl;
}