// g++ -o a.out a.cpp -std=c++17
// oj d https://atcoder.jp/contests/agc_012/tasks/agc_012_a
// oj t -c "./a.out"
// oj s https://atcoder.jp/contests/agc_012/tasks/agc_012_a a.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main(void)
{
  int N;
  cin >> N;
  int A[N];
  rep(i, N) {
    cin >> A[i];
  }
  // 0: none, 1: ascending, 2: decreasing
  int mode = 0;
  int ans = 0;
  for (int i = 1; i < N; i++) {
    if (A[i-1] < A[i]) {
      if (mode == 2) {
        ans++;
        mode = 0;
      } else {
        mode = 1;
      }
    } else if (A[i-1] > A[i]) {
      if (mode == 1) {
        ans++;
        mode = 0;
      } else {
        mode = 2;
      }
    }
  }
  cout << ans + 1 << endl;
}