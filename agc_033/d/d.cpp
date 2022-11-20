// g++ -o d.out d.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc186/tasks/abc186_d
// oj t -c "./d.out"
// oj s https://atcoder.jp/contests/abc186/tasks/abc186_d d.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;

int main(void)
{
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  vector<long long> S(N+1, 0);
  for (int i = 0; i < N; ++i) S[i+1] = S[i] + A[i];

  long long ans = 0;
  for (int i = 0; i < N; i++) {
    ans += A[i] * i - S[i];
  }
  cout << ans << endl;
  return 0;
}