// g++ -o b.out b.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc233/tasks/abc233_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc233/tasks/abc233_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main()
{
  int N;
  cin >> N;
  int H[N+1];
  rep1(i, N) {
    cin >> H[i];
  }
  rep1(i, N) {
    if (i < N && H[i] < H[i+1]) {
    } else {
      cout << H[i] << endl;
      break;
    }
  }
  return 0;
}