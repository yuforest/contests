#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int N, K;
  cin >> N >> K;
  int ans = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= K; j++) {
      int num = i * 100 + j;
      ans += num;
    }
  }
  cout << ans << endl;
}