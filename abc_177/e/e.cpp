// g++ -o c.out c.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc216/tasks/abc216_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc216/tasks/abc216_c c.cpp

#include <bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

// xを割り切れる最小の素数
vector<ll> D(1000010, 0);

// log(x)で素因数分解できる
vector<ll> fast_prime_fact(ll x) {
  vector<ll> primes;
  while(1 < x) {
    primes.push_back(D[x]);
    // xはD[x]で割り切れるので切り捨ては発生しない、xをxをD[x]で割ったもので更新
    x /= D[x];
  }
  return primes;
}

// greatest common divisor
ll gcd(ll a, ll b) { return a ? gcd(b % a, a) : b; }
// least common multiple
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }


int main(void)
{
  ll N;
  cin >> N;
  ll A[N];
  rep(i, N) {
    cin >> A[i];
  }
  // 下準備
  for(ll i = 2; i < 1000010; i++) {
    // D[i]が0でない場合素数でないのでスキップ
    if (D[i] != 0) continue;
    // iの倍数を調べる
    for(ll k = 1; k <= 1000000; k++) {
      // 倍数が1000010未満の時だけ配列に値をセット
      if (i * k < 1000010) {
        // まだセットされていなければセットする
        if (D[i * k] == 0) {
          // iの倍数を割り切れる最小の素数はi
          D[i * k] = i;
        }
      } else {
        break;
      }
    }
  }

  bool pair_wise = true;
  vector<ll> prime_used(1000010, 0);
  for(ll i = 0; i < N; i++) {
    // 素因数分解の結果
    vector<ll> prime_list = fast_prime_fact(A[i]);
    // cout << prime_list.size() << endl;
    set<ll> prime_set(prime_list.begin(), prime_list.end());
    // cout << prime_set.size() << endl;
    for(auto element: prime_set) {
      // 1回既に使われている場合はGCD(i, j)は1にはならないものがある
      if (prime_used[element] == 1) {
        pair_wise = false;
        break;
      } else {
        prime_used[element] = 1;
      }
    }
  }
  // pair wiseなら処理終了
  if(pair_wise) {
    cout << "pairwise coprime" << endl;
    return 0;
  }
  // set wiseかどうかを判定(全ての数でGCDを計算した時に1になる)
  ll g = A[0];
  for(ll i = 1; i < N; i++) {
    g = gcd(g, A[i]);
  }
  if (g == 1) {
    cout << "setwise coprime" << endl;
  } else {
    cout << "not coprime" << endl;
  }

  return 0;
}