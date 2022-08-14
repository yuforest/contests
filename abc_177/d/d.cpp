// g++ -o c.out c.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc216/tasks/abc216_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc216/tasks/abc216_c c.cpp

#include <bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main(void)
{
  int N, M;
  cin >> N >> M;
  int A[M], B[M];
  dsu uf(N);
  rep(i, M) {
    cin >> A[i] >> B[i];
    A[i]--;
    B[i]--;
    if (uf.same(A[i], B[i]) == false) {
      uf.merge(A[i], B[i]);
    }
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    ans = max(ans, uf.size(i));
  }
  cout << ans << endl;
  return 0;
}