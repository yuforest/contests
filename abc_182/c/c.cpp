// g++ -o c.out c.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc219/tasks/abc219_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc219/tasks/abc219_c c.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main(void)
{
  string N;
  cin >> N;
  int N_size = N.size();
  int ans = 100;

  for (int bit = 0; bit < (1<<N_size); ++bit) {
    // cout << bit << endl;
    if (bit == 0) continue;
    int sum = 0;
    int count = 0;
    for (int i = 0; i < N_size; ++i) {
      if (bit & (1<<i)) { // 列挙に i が含まれるか
        sum += N[i] - '0';
      } else {
        count++;
      }
    }
    if (sum % 3 == 0) {
      ans = min(ans, count);
    }
  }

  if (ans == 100) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
}