// g++ -o c.out c.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc216/tasks/abc216_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc216/tasks/abc216_c c.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;
using ll = long long;

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

int main() {
  long long N, P;
  cin >> N >> P;
  const auto &res = prime_factorize(P);
  // cout << P << ":";
  ll ans = 1;
  for (auto p : res) {
    if (p.second >= N) {
      ll index = p.second / N;
      ans *= pow(p.first, index);
    }
    // for (int i = 0; i < p.second; ++i) cout << " " << p.first;
  }
  cout << ans << endl;
}