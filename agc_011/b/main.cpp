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
  ll N;
  cin >> N;
  vector<ll> A(N+1);
  rep(i, N) {
    cin >> A[i+1];
  }
  sort(A.begin(), A.end());
  vector<ll> cumulative(N+1, 0);
  cumulative[0] = 0;
  for(ll i = 1; i <= N; i++) {
    cumulative[i] = cumulative[i-1] + A[i];
  }
  ll ans = 1;
  for(ll i = N-1; i >= 0; i--) {
    if (cumulative[i] * 2 >=  A[i+1]) ans++;
    else break;
  }
  cout << ans << endl;
}