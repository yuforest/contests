// g++ -o a.out a.cpp -std=c++17
// oj d https://atcoder.jp/contests/agc_012/tasks/agc_012_a
// oj t -c "./a.out"
// oj s https://atcoder.jp/contests/agc_012/tasks/agc_012_a a.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;

int main(void)
{
  long long A, B, C;
  cin >> A >> B >> C;
  long long ans = 0;
  while(true) {
    if (A % 2 == 1 || B % 2 == 1 || C % 2 == 1) {
      break;
    }
    if (A == B && B == C) {
      cout << -1 << endl;
      return 0;
    }
    long long tmp_a = (B + C) / 2;
    long long tmp_b = (C + A) / 2;
    long long tmp_c = (A + B) / 2;
    A = tmp_a;
    B = tmp_b;
    C = tmp_c;

    ans++;
  }
  cout << ans << endl;
}