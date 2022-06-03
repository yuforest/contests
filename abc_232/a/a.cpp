// g++ -o a.out a.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc232/tasks/abc232_a
// oj t -c "./a.out"
// oj s https://atcoder.jp/contests/abc232/tasks/abc232_a a.cpp

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
  int a = S.at(0) - '0';
  int b = S.at(2) - '0';
  cout << a * b << endl;
}