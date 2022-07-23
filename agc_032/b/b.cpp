// g++ -o b.out b.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc233/tasks/abc233_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc233/tasks/abc233_b b.cpp


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
  int A[N+1];
  rep1(i, N) {
    cin >> A[i];
  }
  int sum = 0;
  vector<int> B(N+1);
  B[0] = 0;
  rep1(i, N) {
    sum += A[i];
    if (sum >= 360) {
      B[i] = sum % 360;
    } else {
      B[i] = sum;
    }
  }
  sort(B.begin(), B.end());
  int ans = 0;
  rep1(i, N) {
    if (i == N) {
      ans = max(ans, 360-B[i]);
    } else {
      ans = max(ans, B[i] - B[i-1]);
    }
  }
  cout << ans << endl;
  return 0;
}