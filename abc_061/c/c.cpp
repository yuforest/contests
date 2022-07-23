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
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main(void)
{
  ll N, K;
  cin >> N >> K;
  ll a[N], b[N];
  rep(i, N) {
    cin >> a[i] >> b[i];
  }

  vector<pair<ll, ll>> nums;
  rep(i, N) {
    pair<ll, ll> tmp = {a[i], b[i]};
    nums.push_back(tmp);
  }
  sort(nums.begin(), nums.end());
  // sort(nums.begin(), nums.end(), [](auto &x, auto &y) { return x[0] > y[0]; });
  ll sum = 0;
  ll ans;
  rep(i, nums.size()) {
    sum += nums[i].second;
    if (sum >= K) {
      ans = nums[i].first;
      break;
    }
  }
  cout << ans << endl;

}