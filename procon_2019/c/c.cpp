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
using ll = long long;

int main(void)
{
  ll K, A, B;
  cin >> K >> A >> B;
  ll bisket = 0;
  ll yen = 0;
  ll operation = K;
  if (A + 2 >= B) {
    bisket += K + 1;
  } else {
    ll sum = 1;
    // 最初A枚になるまでためる
    sum += min(A - 1, K);
    K -= min(A - 1, K);
    // AB交換する(K/2回交換できる、増える数はB-A枚)、A-1よりKが小さい時はKが0になるので交換されない
    sum += (K / 2) * (B - A);
    K %= 2; //0か1になる
    bisket = sum + K;
  }
  cout << bisket << endl;
}