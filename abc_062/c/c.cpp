// g++ -o a.out a.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc222/tasks/abc222_a
// oj t -c "./a.out"
// oj s https://atcoder.jp/contests/abc222/tasks/abc222_a c.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;

int main(void)
{
  int S;
  cin >> S;
  while {
    if (S.size() == 4) {
      break;
    }
    S = "0" + S;
  }
  cout << S << endl;
}