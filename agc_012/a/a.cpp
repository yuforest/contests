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
  int N;
  cin >> N;
  vector<long long> A(3 * N);
  for (int i = 0; i < 3 * N; i++) {
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  long long sum = 0;
  for (int i = 0; i < N; i++) {
    int index = (3 * N) - (i * 2) - 2;
    sum += A[index];
  }
  cout << sum << endl;
}