// g++ -o c.out c.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc218/tasks/abc218_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc218/tasks/abc218_c c.cpp

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
  vector<string> S(N);
  vector<string> T(N);
  for (int i = 0; i < N; i++) {
    cin >> S[i];
    cout << S[i] << endl;
  }
  for (int i = 0; i < N; i++) {
    cin >> T[i];
    cout << T[i] << endl;;
  }

}