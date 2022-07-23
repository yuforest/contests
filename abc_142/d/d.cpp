// g++ -o d.out d.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc233/tasks/abc233_d
// oj t -c "./d.out"
// oj s https://atcoder.jp/contests/abc233/tasks/abc233_d d.cpp


#include <bits/stdc++.h>
// #define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
long long minimum_time = 0;
vector<bool> used(200007, false);
vector<vector<int>> G1(10, vector<int>());
vector<vector<int>> G2(10, vector<int>());
long long K[200007];
long long T[200007];
#include <bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;

ll MAX = 1 << 18;

#define rep(i,l,r) for(ll i=l;i<=r;i++)

int N;
ll X;
int L[100007];
vector<vector<ll>> a(100007, vector<ll>());
ll ans = 0;

// std::vector<bool> IsPrime;

// void sieve(size_t max){
//   if(max+1 > IsPrime.size()){     // resizeで要素数が減らないように
//       IsPrime.resize(max+1,true); // IsPrimeに必要な要素数を確保
//   }
//   IsPrime[0] = false; // 0は素数ではない
//   IsPrime[1] = false; // 1は素数ではない

//   for(size_t i=2; i*i<=max; ++i) // 0からsqrt(max)まで調べる
//     if(IsPrime[i]) // iが素数ならば
//       for(size_t j=2; i*j<=max; ++j) // (max以下の)iの倍数は
//         IsPrime[i*j] = false;      // 素数ではない
// }

bool is_prime(long long n) {  // is n prime or not
  for (long long i = 2; i * i <= n; i++) {
      if (n % i == 0) return false;
  }
  return true;
}

// 別解
// ll gcd(ll a,ll b){return a?gcd(b%a,a):b;}
// // 素因数分解
// map<ll,int> enumpr(ll n) {
// 	map<ll,int> V;
// 	for(ll i=2;i*i<=n;i++) while(n%i==0) V[i]++,n/=i;
//   // 素数の場合
// 	if(n>1) V[n]++;
// 	return V;
// }

// int main(){
//   ll A, B;
//   cin >> A >> B;
//   auto ep = enumpr(gcd(A, B));
//   for(auto e: ep) {
//     cout << e.first << endl;
//     cout << e.second << endl;
//   }
//   // 1があるので1を足している
//   int ans = ep.size() + 1;
//   cout << ans << endl;
// }


int main() {
  ll A, B;
  cin >> A >> B;
  set<ll> dividers;
  if (B > A) swap(A, B);
  for(ll i = 1; i * i <= A; i++) {
    if (A % i == 0 && B % i == 0) dividers.insert(i);
    if (A % i == 0) {
      ll second = A / i;
      if (B % second == 0) {
        dividers.insert(second);
      }
    }
  }
  ll ans = 0;
  for(auto divider: dividers) {
    if (is_prime(divider)) ans++;
    // cout << divider << endl;
  }
  cout << ans << endl;
}


