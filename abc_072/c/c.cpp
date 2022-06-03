// g++ -o c.out c.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc213/tasks/abc213_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc213/tasks/abc213_c c.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;

int main(void)
{
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  map<int, int> table;
  for (int i = 0; i < N; i++) {
    table[A[i]]++;
  }
  sort(A.begin(), A.end());
  int rangeMin = A[0];
  int rangeMax = A[N-1];
  int ans = 0;
  for (int i = rangeMin; i <= rangeMax; i++) {
    int count  = table[i-1] + table[i] + table[i+1];
    ans = max(ans, count);
  }
  cout << ans << endl;
}