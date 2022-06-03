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
 long long N;
 cin >> N;
 if (N == 1) {
   cout << "Yes" << endl;
 } else if (N <= 4) {
   cout << "No" << endl;
 } else {
   cout << "Yes" << endl;
 }

  return 0;
}