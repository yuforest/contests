// g++ -o c.out c.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc226/tasks/abc226_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc226/tasks/abc226_c c.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
long long minimum_time = 0;
vector<bool> used(200007, false);
vector<int> G[1 << 18];
long long K[200007];
long long T[200007];


int main()
{
  int N;
  cin >> N;
  int a[N];
  rep(i, N) {
    cin >> a[i];
  }
  // 4x
  int x = 0;
  // 2x and not 4x
  int y = 0;
  rep(i, N) {
    if (a[i] % 4 == 0) {
      x++;
    } else if (a[i] % 2 == 0) {
      y++;
    }
  }
  // not 2x and not 4x
  int other = N - x - y;
  if (y > 0) other++;
  // cout << other << endl;
  // cout << x << endl;
  if (other - (x + 1) > 0) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
}