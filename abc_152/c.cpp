#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int N;
  cin >> N;
  int P[N];
  int min_P = 200007;
  int ans = 0;
  rep(i, N) {
    cin >> P[i];
    if (P[i] <= min_P) ans++;
    min_P = min(min_P, P[i]);
  }
  cout << ans << endl;
  return 0;
}