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
  int N, M;
  cin >> N;
  map<string, int> plus;
  map<string, int> minus;
  rep(i, N) {
    string val;
    cin >> val;
    plus[val]++;
  }
  cin >> M;
  rep(i, M) {
    string val;
    cin >> val;
    minus[val]++;
  }
  int ans = 0;
  for(auto e: plus) {
    ans = max(ans, plus[e.first] - minus[e.first]);
  }
  cout << ans << endl;
}