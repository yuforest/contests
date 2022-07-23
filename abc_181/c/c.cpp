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
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main(void)
{
  int N;
  cin >> N;
  int x[N], y[N];
  rep(i, N) {
    cin >> x[i] >> y[i];
  }
  string ans = "No";
  for (int i = 0; i < N; i++) {
    for(int j = i+1; j < N; j++) {
      for(int k = j+1; k < N; k++) {
        int dx1 = x[k] - x[i], dy1 = y[k] - y[i];
        int dx2 = x[j] - x[i], dy2 = y[j] - y[i];
        // int dx1 = x[j] - x[i];
        // int dx2 = x[k] - x[i];
        // int dy1 = y[j] - y[i];
        // int dy2 = y[k] - y[i];
        if (dx2 * dy1 == dx1 * dy2) {
          ans = "Yes";
        }
      }
    }
  }
  cout << ans << endl;



}