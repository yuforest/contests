#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int K;
  cin >> K;
  vector<ll> a;
  for(int i = 1; i <= 9; i++) a.push_back(i);
  while (1) {
    if ( K <= a.size()) {
      cout << a[K-1] << endl;
      return 0;
    }
    K -= a.size();
    vector<ll> old;
    swap(old, a);
    for (ll x: old) {
      for (int i = -1; i <= 1; i++) {
        int d = x%10 + i;
        if (d< 0 || d > 9) continue;
        ll nx = x*10 + d;
        a.push_back(nx);
      }
    }
  }
  return 0;
}