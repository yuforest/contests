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
  rep(i, N) {
    cin >> A[i];
  }
  sort(A.begin(), A.end(), greater<int>());
  ll first = A[0];
  double half = first / 2.0;
  ll second = A[N-1];
  for(int i = 1; i < N; i++) {
    // cout << abs(A[i] - half) << endl;
    // halfに近い数を探す
    if (abs(A[i] - half) <= abs(second - half)) {
      second = A[i];
    }
  }
  cout << first << " " << second << endl;
}