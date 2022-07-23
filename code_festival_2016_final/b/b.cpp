// g++ -o b.out b.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc216/tasks/abc216_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc216/tasks/abc216_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int N;
  cin >> N;
  int ans = 0;
  int diff = 0;
  int sum = 0;
  for (int i = 1; i <= N; i++) {
    sum += i;
    if (sum >= N) {
      diff = sum - N;
      ans = i;
      break;
    }
  }

  // cout << ans << endl;
  // cout << diff << endl;

  for (int i = 1; i <= ans; i++) {
    if (i == diff) continue;
    cout << i << endl;
  }

}