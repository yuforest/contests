// g++ -o b.out b.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc226/tasks/abc226_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc226/tasks/abc226_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main()
{
  int N, K;
  cin >> N >> K;
  int x[N+1];
  rep1(i, N) {
    cin >> x[i];
  }
  int sum = 0;
  rep1(i, N) {
    sum += min(x[i] * 2, (K - x[i]) * 2);
  }
  cout << sum << endl;

}