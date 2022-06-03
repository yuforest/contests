// g++ -o c.out c.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc217/tasks/abc217_d
// oj t -c "./d.out"
// oj s https://atcoder.jp/contests/abc217/tasks/abc217_d d.cpp

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
  long long X[N];
  long long Y[N];
  for (int i = 0; i < N; i++) {
    cin >> X[i];
    cin >> Y[i];
  }
  int count = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == j) continue;
      if (Y[i] != Y[j]) continue;
      if (X[i] < X[j]) continue;
      for (int k = 0; k < N; k++) {
        if (j == k) continue;
        if (i == k) continue;
        if (X[j] != X[k]) continue;
        if (Y[j] < Y[k]) continue;
        for (int l = 0; l < N; l++) {
          if (j == l) continue;
          if (i == l) continue;
          if (k == l) continue;
          if (Y[k] != Y[l]) continue;
          if (X[i] != X[l]) continue;
          // cout << X[i] << Y[i] << endl;
          // cout << X[j] << Y[j] << endl;
          // cout << X[k] << Y[k] << endl;
          // cout << X[l] << Y[l] << endl;
          count++;
        }
      }
    }
  }
  cout << count << endl;
}