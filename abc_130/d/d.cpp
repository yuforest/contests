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
#define rep(i, n) for (int i = 0; i < (n); ++i)

int dp[33][101010];
int ans[101010];
using ll = long long;

int main(void)
{
  ll N, K;
  cin >> N >> K;
  ll A[N];
  rep(i, N) {
    cin >> A[i];
  }

  ll ans = 0;
  ll sum = 0;

  // しゃくとり法
  int r = 0;
  for(int l = 0; l < N; l++) {
    while(sum < K) {
      if (r == N) break;
      else {
        sum += A[r];
        r++;
      }
    }
    // これ以降進めてもsumがK以上になることはない
    if (sum < K) break;
    // 区間の初めてKを超えたところより右側を加算する
    ans += N - r + 1;
    sum -= A[l];
  }
  cout << ans << endl;
  return 0;

}