// g++ -o c.out c.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc216/tasks/abc216_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc216/tasks/abc216_c c.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;

int main(void)
{
  int n;
  cin >> n;
  vector<int> A(n);
  for(int i = 0; i < n; i++) cin >> A[i];
  vector<int> B(n);
  for(int i = 0; i < n; i++) cin >> B[i];

  // 十分に準備度がある試験の配列
  vector<long long> rem(n, 0);

  int count = 0;
  long long sum = 0;

  for (int i = 0; i < n; i++) {
    // 準備度が十分な場合
    if (A[i] >= B[i]) {
      // 大きい方から小さい方を引いている
      rem[i] = A[i] - B[i];
    } else {
      // 不足している準備度
      sum += B[i] - A[i];
      count++;
    }
  }

  // 大きい順にソート
  sort(rem.begin(), rem.end(), greater<long long>());

  // sumが0以下になるまで引いていく
  for (int i = 0; sum > 0 && i < n; i++) {
    sum -= rem[i];
    count++;
  }

  int ans = sum > 0 ? -1 : count;
  cout << ans << endl;

  return 0;
}