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
  int H, W;
  cin >> H >> W;
  int A[H+1][W+1];
  rep1(i, H) {
    rep1(j, W) {
      cin >> A[i][j];
    }
  }
  rep1(i, W) {
    rep1(j, H) {
      cout << A[j][i];
      if (j != 0) cout << " ";
    }
    cout << endl;
  }
  return 0;
}