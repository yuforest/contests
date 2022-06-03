// g++ -o b.out b.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc226/tasks/abc226_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc226/tasks/abc226_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int N;
  cin >> N;
  int A[N+1];
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }
  int count  = 0;
  int current = 1;
  while (count <= N) {
    if (current == 2) {
      break;
    }
    current = A[current];
    count++;
  }
  if (count == N+1) {
    cout << -1 << endl;
  } else {
    cout << count << endl;
  }
}