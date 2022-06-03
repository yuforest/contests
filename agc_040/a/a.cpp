// g++ -o a.out a.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc235/tasks/abc235_a
// oj t -c "./a.out"
// oj s https://atcoder.jp/contests/abc235/tasks/abc235_a a.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;

int main(void)
{
  string S;
  cin >> S;
  int length = (int)S.size();
  vector<int> A(length + 1, 0);

  for (int i = 0; i < length; i++) {
    if (S.at(i) == '<') A.at(i + 1) = A.at(i) + 1;
  }

  for (int i = length - 1; i >= 0; i--) {
    if (S.at(i) == '>') A.at(i) = max(A.at(i), A.at(i + 1) + 1);
  }

  int64_t ans = 0;
  for (int a: A) ans += a;
  
  cout << ans << endl;

  return 0;
}