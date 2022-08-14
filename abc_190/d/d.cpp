// g++ -o d.out d.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc222/tasks/abc222_d
// oj t -c "./d.out"
// oj s https://atcoder.jp/contests/abc222/tasks/abc222_d d.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
// long long mod = 1000000007;
// 縦軸が弁当の種類、横軸がたこ焼きの数、配列の値が鯛焼きの数
int dp[301][301][301];

#include <iostream>
#include <cmath>
using ll = int64_t;

int main(){
  ll N;
  cin >> N;
  ll i = 1;
  ll ans = 0;
  // x = (B-A+1), y = (A+B)となる組の数え上げ問題に帰着させる
  // またA = (y-x+1)/2, B= (x+y-1)/2よりx,yの偶奇は異なる必要がある
  // 小さい方から順に割っていけば√Nより大きい数は試しわりする必要がない
  while(i * i <= 2 * N) {
    if (2 * N % i == 0) {
      ll x = i;
      ll y = 2 * N / i;
      if (x % 2 != y % 2) {
        ans += 2;
      }
    }
    i++;
  }
  cout << ans << endl;
}
