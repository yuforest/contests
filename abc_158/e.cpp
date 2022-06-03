#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  // int N, P;
  // string S;
  // cin >> N >> P >> S;
  // ll ans = 0;
  // for (int i = 0; i < N; i++) {
  //   ll val = S[i] - '0';
  //   if (val % P == 0) {
  //     ans++;
  //   }
  //   ll sum = val;
  //   for (int j = i+1; j < N; j++) {
  //     sum += S[j] - '0';
  //     if (sum % P == 0) {
  //       ans++;
  //     }
  //   }
  // }
  // cout << ans << endl;


  int n, p;
  cin >> n >> p;
  string s;
  cin >> s;
  if (10%p == 0) {
    ll ans = 0;
    rep(r, n) {
      if ((s[r]-'0') % p == 0) {
        ans += r+1;
      }
    }
    cout << ans << endl;
    return 0;
  }

  vector<int> d(n+1);
  int ten = 1;
  for (int i = n-1; i >= 0; --i) {
    int a = (s[i]-'0') * ten % p;
    d[i] = (d[i+1]+a) % p;
    ten *= 10; ten %= p;
  }
  vector<int> cnt(p);
  ll ans = 0;
  for (int i = n; i >= 0;--i) {
    // cout << cnt[d[i]] << endl;
    cout << d[i] << endl;
    ans += cnt[d[i]];
    cnt[d[i]]++;
  }
  cout << ans << endl;
  return 0;

}