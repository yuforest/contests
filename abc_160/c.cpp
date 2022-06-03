#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int K, N;
  cin >> K >> N;
  int A[N];
  rep(i, N) {
    cin >> A[i];
  }
  int ans = A[N - 1] - A[0];
  for (int i = 1; i < N; i++) {
    int i_to_start = K - A[i];
    int start_to_i1 = A[i - 1];
    ans = min(ans, i_to_start + start_to_i1);
  }
  cout << ans << endl;
}