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
  int N;
  cin >> N;
  int H[N];
  int ans = 0;
  rep(i, N) {
    cin >> H[i];
  }
  int max_height = 0;
  rep(i, N) {
    if (H[i] >= max_height) ans++;
    max_height = max(max_height, H[i]);
  }
  cout << ans << endl;
}