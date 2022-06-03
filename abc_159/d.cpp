#include <bits/stdc++.h>
#define rep(i, first, n) for (int i = first; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int N, A[201010];
ll cnt[201010];

int main() {
  cin >> N;
  rep(i, 0, N) cin >> A[i];

  ll all = 0;
  rep(i, 0, N) cnt[A[i]]++;
  rep(i, 1, N + 1) all += cnt[i] * (cnt[i] - 1) / 2;

  rep(i, 0, N) {
      ll ans = all;
      ans -= cnt[A[i]] * (cnt[A[i]] - 1) / 2;
      ans += (cnt[A[i]] - 1) * (cnt[A[i]] - 2) / 2;
      printf("%lld\n", ans);
  }
  return 0;
}