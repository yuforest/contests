#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int mod = 1000000007;

int calcNumOfCombination(int n, int r)
{
  int num = 1;
  for (int i = 1; i <= r; i++) {
    num = num * (n - i + 1) / i;
  }
  return num - (n - r - 1);
}

int main()
{
  int N, K;
  cin >> N >> K;
  ll ans = 0;

  for(int i = K; i <= N+1; ++i) {
    ll val = calcNumOfCombination(N+1, i) % mod;
    ans += val;
  }
  if (N+1 == K) {
    cout << 1 << endl;
  } else {
    cout << ans << endl;
  }
}