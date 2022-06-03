#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int N;
  cin >> N;
  int A[N];
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (A[i] <= 10) {
      continue;
    } else {
      ans += A[i] - 10;
    }
  }
  cout << ans << endl;
}