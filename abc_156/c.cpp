#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF = ll(1e18) + 1;

int main()
{
  int n;
  cin >> n;
  vector<ll> X(n);
  rep(i, n) cin >> X[i];

  ll ans = INF;
  sort(X.begin(), X.end());
  // rep(i, n) cout << X[i] << " ";
  // cout << X[0] << endl;
  // cout << X[X.size() - 1] << endl;

  for (int i = X[0]; i <= X[X.size() - 1]; i++)
  {
    ll hp = 0;
    for (int j = 0; j < n; j++) {
      hp += pow((X[j] - i), 2);
      // cout << hp << endl;
    }
    ans = min(hp, ans);
  }
  cout << ans << endl;
}