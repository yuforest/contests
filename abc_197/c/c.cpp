// g++ -o c.out c.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc213/tasks/abc213_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc213/tasks/abc213_c c.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)
ll A[21];

ll calc_or(ll left, ll right) {
  ll result = 0;
  for(ll i = left; i < right; i++) {
    result = result | A[i];
  }
  return result;
}

int main(void)
{
  ll N;
  cin >> N;
  rep(i, N) {
    cin >> A[i];
  }
  ll ans = LLONG_MAX;
  // 仕切りの構造をbit全探索する
  for(ll i = 0; i < (1 << N+1); i++) {
    // 左端か右端が0になっているものは計算しない
    if ((i & 1) == 0 || ((i >> N) & 1) == 0) continue;
    vector<ll> partitions = {};
    // cout << i << endl;
    for(ll shift = 0; shift < N+1; shift++) {
      if (i >> shift & 1 == 1) {
        // cout << "shikiri: " << shift << endl;
        partitions.push_back(shift);
      }
    }
    ll tmp = 0;
    for(int j = 0; j < partitions.size()-1; j++) {
      tmp = tmp ^ calc_or(partitions[j], partitions[j+1]);
    }
    ans = min(ans, tmp);
  }
  cout << ans << endl;
}