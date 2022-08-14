// g++ -o d.out d.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc174/tasks/abc174_d
// oj t -c "./d.out"
// oj s https://atcoder.jp/contests/abc174/tasks/abc174_d d.cpp

#include <bits/stdc++.h>
using namespace std;
int c[300005];
map<int, int> mp;
// long long mod = 1000000007;
// 縦軸が弁当の種類、横軸がたこ焼きの数、配列の値が鯛焼きの数
int dp[301][301][301];

vector<pair<long long, long long> > prime_factorize(long long N) {
  vector<pair<long long, long long> > res;
  for (long long a = 2; a * a <= N; ++a) {
    if (N % a != 0) continue;
    long long ex = 0; // 指数

    // 割れる限り割り続ける
    while (N % a == 0) {
        ++ex;
        N /= a;
    }

    // その結果を push
    res.push_back({a, ex});
  }

  // 最後に残った数について
  if (N != 1) res.push_back({N, 1});
  return res;
}

using namespace std;
int n;
string s;
using ll = long long;
int main()
{
  ll N;
  cin >> N;
  const auto &res = prime_factorize(N);
  ll ans = 0;
  for(auto factor: res) {
    ll tmp = 0;
    ll current = 0;
    while(true) {
      current++;
      if (tmp + current <= factor.second) {
        ans++;
      } else {
        break;
      }
      tmp += current;
    }
    // cout << factor.first << endl;
    // cout << factor.second << endl;
  }
  cout << ans << endl;

}
