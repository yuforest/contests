// g++ -o a.out a.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc217/tasks/abc217_a
// oj t
// oj s https://atcoder.jp/contests/abc217/tasks/abc217_a a.cpp

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
	ll N, x;
  cin >> N >> x;
  vector<ll> a(N);
  rep(i, N) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int ans = 0;
  bool completed = false;
  rep(i, N) {
    if (x >= a[i]) {
      x -= a[i];
      ans++;
      if (i == (int)a.size()-1) {
        completed = true;
      }
    } else {
      break;
    }
  }
  if (completed && x != 0) {
    ans--;
  }
  cout << ans << endl;

}