// g++ -o c.out c.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc216/tasks/abc216_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc216/tasks/abc216_c c.cpp

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (n); ++i)


ll powmod(ll x,ll y){
    ll res=1;
    for(ll i=0;i<y;i++){
      res=res*x%mod;
    }
    return res;
}

int main(void)
{
  ll N;
  cin >> N;
  ll ans = powmod(10, N) - powmod(9, N) - powmod(9, N) + powmod(8, N);
  ans %= mod;
  ans=(ans+mod)%mod;
  cout << ans << endl;
  return 0;
}