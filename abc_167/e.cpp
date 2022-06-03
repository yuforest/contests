#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i <= (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int N;
  cin >> N;
  vector<int> A(N+1);
  rep1(i, N) {
    cin >> A[i];
  }
  ll ans = 0;
  map<int, int> mp;
  rep1(i, N) {
    mp[i+A[i]]++;
  }
  rep1(i, N) {
    ans += mp[i-A[i]];
  }
  cout << ans << endl;
}