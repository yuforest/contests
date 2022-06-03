// g++ -o b.out b.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc216/tasks/abc216_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc216/tasks/abc216_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int N;
  cin >> N;
  int devided = (N-1) / 20;
  int remaining = N - (20 * devided);
  if (devided % 2 == 0) {
    cout << remaining << endl;
  } else {
    cout << 21 - remaining << endl;
  }
}