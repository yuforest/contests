// g++ -o a.out a.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc222/tasks/abc222_a
// oj t -c "./a.out"
// oj s https://atcoder.jp/contests/abc222/tasks/abc222_a a.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;

int main(void)
{
  int A, B;
  cin >> A >> B;
  int ans = max(max(max(max(max(max(-100000,(A%100+900-B)),((A/100)*100+A%10+90)-B),A+9-A%10-B),A-(B%100+100)),A-((B/100)*100+B%10)),A-(B-B%10));
  cout<< ans <<endl;
  return 0;
}