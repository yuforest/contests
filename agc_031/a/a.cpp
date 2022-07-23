// g++ -o a.out a.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc217/tasks/abc217_a
// oj t
// oj s https://atcoder.jp/contests/abc217/tasks/abc217_a a.cpp

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
long long mod = 1000000007;

int main() {
	int N;
  string S;
  cin >> N >> S;
  map<char, ll> mp;
  for (auto c: S) {
    mp[c]++;
  }
  ll ans = 1;
  for(auto e: mp) {
    ans *= e.second+1;
    ans %= mod;
  }
  ans -= 1;
  cout << ans << endl;
}