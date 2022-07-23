// g++ -o a.out a.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc222/tasks/abc222_a
// oj t -c "./a.out"
// oj s https://atcoder.jp/contests/abc222/tasks/abc222_a c.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main(void)
{
  ll N;
  cin >> N;
  ll A[N];
  rep(i, N) {
    cin >> A[i];
  }
  map<ll, ll> mp;
  rep(i, N) {
    mp[A[i]]++;
  }
  ll first = 0;
  ll second = 0;
  for(auto e: mp) {
    if (e.first > first && e.second >= 2) {
      second = first;
      first = e.first;
    }
  }
  // cout << first << endl;
  // cout << second << endl;
  if (mp[first] >= 4) {
    cout << first * first << endl;
  } else if (mp[first] >= 2 && mp[second] >= 2) {
    cout << first * second << endl;
  } else if (mp[second] >= 4) {
    cout << second * second << endl;
  } else {
    cout << 0 << endl;
  }
}