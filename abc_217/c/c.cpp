// g++ -o c.out c.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc217/tasks/abc217_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc217/tasks/abc217_c c.cpp

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
  int A[N+1];
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }
  int ans[N+1];
  for (int i = 1; i <= N; i++) {
    ans[A[i]] = i;
  }

  for (int i = 1; i <= N; i++) {
    if (i != 1) {
      cout << " ";
    }
    cout << ans[i];
  }
  cout << endl;
}