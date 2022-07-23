// g++ -o c.out c.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc216/tasks/abc216_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc216/tasks/abc216_c c.cpp

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;

int main(void)
{
  long long X, K, D;
  cin >> X >> K >> D;
  X = abs(X);

  // 移動できる回数と0近くに移動するための回数の小さい方、これが最小値
  ll straight = min(K, X / D);
  K -= straight;
  X -= straight * D;

  // 残り回数が偶数ならその位置のまま
  if (K % 2 == 0) {
    cout << X << endl;
  } else {
    // 奇数なら0を飛び越えたところに行って終了
    cout << D - X << endl;
  }
}