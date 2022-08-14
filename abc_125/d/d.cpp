// g++ -o d.out d.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc222/tasks/abc222_d
// oj t -c "./d.out"
// oj s https://atcoder.jp/contests/abc222/tasks/abc222_d d.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
// long long mod = 1000000007;
// 縦軸が弁当の種類、横軸がたこ焼きの数、配列の値が鯛焼きの数
int dp[301][301][301];
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main(void)
{
  ll N;
  cin >> N;
  vector<ll> A(N);
  vector<ll> absolute_A(N);
  ll negative_count = 0;
  ll abs_sum = 0;
  rep(i, N) {
    cin >> A[i];
    absolute_A[i] = abs(A[i]);
    abs_sum += abs(A[i]);
    if (A[i] < 0) negative_count++;
  }
  sort(absolute_A.begin(), absolute_A.end());
  ll ans;
  // cout << negative_count << endl;
  // cout << absolute_A[0] << endl;
  if (negative_count % 2 == 0) {
    ans = abs_sum;
  } else {
    ans = abs_sum - (absolute_A[0] * 2);
  }
  cout << ans << endl;
}