// g++ -o b.out b.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc216/tasks/abc216_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc216/tasks/abc216_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  ll N, M;
  cin >> N;
  ll D[N];
  map<ll, ll> D_map;
  rep (i, N) {
    cin >> D[i];
    D_map[D[i]]++;
  }
  cin >> M;
  ll T[M];
  map<ll, ll> T_map;
  rep (i, M) {
    cin >> T[i];
    T_map[T[i]]++;
  }
  string ans = "YES";

  for(auto t: T_map) {
    if (t.second > D_map[t.first]) {
      ans = "NO";
    }
  }
  cout << ans << endl;
}