// g++ -o b.out b.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc256/tasks/abc256_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc256/tasks/abc256_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
map<int, int> mp;

int main()
{
  int N;
  cin >> N;
  int A[N];
  rep(i, N) {
    cin >> A[i];
  }
  int P = 0;
  vector<int> ans(N, 0);
  rep(i, N) {
    for (int j = i; j < N; j++) {
      ans[i] += A[j];
    }
  }
  rep(i, N) {
    if (ans[i] >= 4) {
      P++;
    }
  }
  cout << P << endl;
  return 0;
}