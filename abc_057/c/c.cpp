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

ll f(ll a, ll b) {
  return max(to_string(a).size(), to_string(b).size());
}

int main(void)
{
  ll N;
  cin >> N;
  // 素数の配列
  auto prime_pairs = prime_factorize(N);
  vector<ll> primes = {};
  for(int i = 0; i < prime_pairs.size(); i++) {
    auto prime_pair = prime_pairs[i];
    for(int j = 0; j < prime_pair.second; j++) {
      primes.push_back(prime_pair.first);
      // cout << prime_pair.first << endl;
    }
  }
  ll ans = 10000;
  for(int bit = 0; bit < (1 << primes.size()); bit++) {
    // 生成したbitに対して選ばれているかを探索
    ll a = 1;
    ll b = 1;
    // cout << bit << endl;
    for(int i = 0; i < primes.size(); i++) {
      // 列挙に i が含まれるか
      if(bit & (1<<i)) {
        a *= primes[i];
      } else {
        b *= primes[i];
      }
    }
    ans = min(ans, f(a, b));
    // cout << "a and b" << endl;
    // cout << a << endl;
    // cout << b << endl;
  }


  cout << ans << endl;
}