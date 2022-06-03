#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  ll N, A, B;
  cin >> N >> A >> B;
  if (A == 0) {
    cout << 0 << endl;
    return 0;
  }
  ll rest = N % (A+B);
  ll sho = N / (A+B);
  ll ans = sho * A;
  if (rest <= A) {
    ans += rest;
  }else{
    ans += A;
  }
  cout << ans << endl;
}