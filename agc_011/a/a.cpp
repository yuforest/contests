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
  int N, C, K;
  cin >> N >> C >> K;
  vector<int> T(N);
  rep(i, N) {
    cin >> T[i];
  }
  sort(T.begin(), T.end());
  int ans = 0;
  int current = 0;
  int count = 0;
  for (int i = 0; i < N; i++) {
    current = T[i];
    count++;
    while(true) {
      if (count < C && current + K >= T[i+1]) {
        count++;
        i++;
      } else {
        break;
      }
    }
    ans++;
    count = 0;
  }
  cout << ans << endl;
}