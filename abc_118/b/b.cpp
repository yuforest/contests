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
  int N, M;
  cin >> N >> M;
  map<int, int> mp;
  rep(i, N) {
    int K;
    cin >> K;
    rep(j, K) {
      int A;
      cin >> A;
      mp[A]++;
    }
  }
  int ans = 0;
  for(auto e: mp) {
    if (e.second == N) ans++;
  }
  cout << ans << endl;
  return 0;
}