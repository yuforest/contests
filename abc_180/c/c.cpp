// g++ -o c.out c.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc219/tasks/abc219_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc219/tasks/abc219_c c.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;

int main(void)
{
  string X;
  int N;
  cin >> X;
  cin >> N;
  vector<string> S(N);
  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < S[i].size(); j++) {
      for (int k = 0; k < X.size(); k++) {
        if (S[i][j] == X[k]) {
          S[i][j] = k + '0';
        }
      }
    }
  }
  sort(S.begin(), S.end());
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < S[i].size(); j++) {
      for (int k = 0; k < X.size(); k++) {
        if (S[i][j] == k + '0') {
          S[i][j] = X[k];
        }
      }
    }
  }
  for (int i = 0; i < N; i++) {
    cout << S[i] << endl;
  }



}