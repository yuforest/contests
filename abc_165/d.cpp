#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  ll A, B, N;
  cin >> A >> B >> N;
  ll x = min(N, B-1);
  ll ans;
  ans = floor(A*x/B) - A * floor(x/B);
  cout << ans << endl;
}