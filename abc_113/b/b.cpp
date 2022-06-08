// g++ -o b.out b.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc226/tasks/abc226_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc226/tasks/abc226_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main()
{
  int N, T, A;
  cin >> N >> T >> A;
  int H[N];
  rep(i, N) {
    cin >> H[i];
  }
  int ans;
  double diff = 10000;
  rep(i, N) {
    double temperature = T - H[i] * 0.006;
    if (abs(temperature - A) < diff) {
      diff = abs(temperature - A);
      ans = i+1;
    }
  }
  cout << ans << endl;
}