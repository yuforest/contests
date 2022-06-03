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
  vector<int> d(N);
  rep (i, N) {
    cin >> d[i];
  }
  sort(d.begin(), d.end());
  int d_size = d.size();
  int first_center = d[d_size / 2 - 1];
  int second_center = d[d_size / 2];
  int ans = 0;
  for (int i = first_center+1; i <= second_center; i++) {
    ans++;
  }
  cout << ans << endl;

}