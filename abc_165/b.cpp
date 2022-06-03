#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int A, B, C, K;
  cin >> A >> B >> C >> K;
  int ans = 0;
  if (A >= K) {
    ans += K;
    cout << ans << endl;
    return 0;
  } else {
    ans += A;
    K = K - A;
    if (B >= K) {
      cout << ans << endl;
      return 0;
    } else {
      K = K - B;
      ans -= K;
      cout << ans << endl;
      return 0;
    }
  }
}