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
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main(void)
{
  int N, K, S;
  cin >> N >> K >> S;
  if (S == pow(10, 9)) {
    rep(i, K) {
      cout << S << " ";
    }
    rep(i, N-K) {
      if (N-K-1 == i) {
        cout << 1 << endl;
      } else {
        cout << 1 << " ";
      }
    }
  } else {
    rep(i, K) {
      cout << S << " ";
    }
    rep(i, N-K) {
      if (N-K-1 == i) {
        cout << S + 1 << endl;
      } else {
        cout << S + 1 << " ";
      }
    }

  }
  return 0;
}