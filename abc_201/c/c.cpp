// g++ -o c.out c.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc201/tasks/abc201_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc201/tasks/abc201_c c.cpp

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
  for (int i = 0; i < 10000; i++) {
    vector<bool> flag(10);
    int X = i;
    for (int j = 0; j < 4; j++) {
      flag[X%10] = true;
      X /= 10;
    }
    bool flag2 = true;
    for (int j = 0; j < 10; j++) {
      if (S[j] == 'o' && !flag[j]) flag2 = false;
      if (S[j] == 'x' && flag[j]) flag2 = false;
    }
    ans += flag2;
  }
  cout << ans << endl;
}