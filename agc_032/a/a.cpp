// g++ -o a.out a.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc235/tasks/abc235_a
// oj t -c "./a.out"
// oj s https://atcoder.jp/contests/abc235/tasks/abc235_a a.cpp

#include <bits/stdc++.h>
using namespace std;
// int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;

#define rep(i, n) for (int i = 0; i < (n); ++i)

int main(void) {
  int N;
  cin >> N;
  int A[N+1], ans[N+1];
  for (int i = 1; i <= N; i++)  {
    cin >> A[i];
  }

  // 最後から埋めていく
  for (int i = N; i >= 1; i--) {
    int p = i;
    for (; p >= 1; p--) {
      // 取り除くことができるボールを発見したとき
      if (A[p] == p) break;
    }
    // pが0に到達した場合(発見できなかったとき)
    if (!p) {
      cout << -1 << endl;
      return 0;
    }
    ans[i] = p;

    // 取り除いたボールから埋めるべき場所の手前までループ(配列をずらすことによってボールの取り除き作業)
    for (int j = p; j < i; j++) {
      A[j] = A[j+1];
    }
  }
  for (int i = 1; i <= N; i++) {
    cout << ans[i] << endl;
  }

  return 0;
}