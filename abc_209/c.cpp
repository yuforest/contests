#include <bits/stdc++.h>
using namespace std;

long long MOD = 1000000007;

int main()
{
  long long N;
  cin >> N;
  vector<long long> C(N, 0);
  for (int i = 0; i < N; i++)
  {
    cin >> C.at(i);
  }
  sort(C.begin(), C.end(), [](int a, int b) {
    return a < b;
  });
  long long ans = 1;
  for (int i = 0; i < N; i++)
  {
    long long val = C.at(i) % MOD;
    val -= i;
    ans *= val;
    ans %= MOD;
  }
  cout << ans << endl;
}