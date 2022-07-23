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
  string S;
  cin >> S;
  int ans = 0;
  for(int i = 0; i < S.size()-1; i++) {
    if (S[i] != S[i+1]) {
      ans++;
    }
  }
  cout << ans << endl;
}