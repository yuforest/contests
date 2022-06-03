#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int N;
  cin >> N;
  vector<double> v(N);
  rep(i, N) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  double ans = (v[0] + v[1]) / 2;
  for (int i = 2; i < N; i++) {
    ans = (ans + v[i]) / 2;
  }
  cout << setprecision(7) << ans << endl;
}