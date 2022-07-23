// g++ -o c.out c.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc213/tasks/abc213_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc213/tasks/abc213_c c.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main(void)
{
  int N;
  string S;
  int Q;
  cin >> N >> S >> Q;
  string S1 = S.substr(0, N);
  string S2 = S.substr(N);
  // cout << S1 << endl;
  // cout << S2 << endl;
  bool swapped = false;
  rep(i, Q) {
    int T, A, B;
    cin >> T >> A >> B;
    if(T == 2) {
      swap(S1, S2);
    } else {
      A--;
      B--;
      if (B < N) swap(S1[A], S1[B]);
      else if (N <= A) swap(S2[A - N], S2[B - N]);
      else swap(S1[A], S2[B - N]);
    }
  }
  cout << S1 + S2 << endl;
}