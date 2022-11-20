// g++ -o b.out b.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc219/tasks/abc219_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc219/tasks/abc219_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{

  int N;
  cin >> N;
  int D1[N], D2[N];
  rep(i, N) cin >> D1[i] >> D2[i];
  string ans = "No";
  rep(i, N-2) {
    if (D1[i] == D2[i] && D1[i+1] == D2[i+1] && D1[i+2] == D2[i+2]) ans = "Yes";
  }
  cout << ans << endl;
}