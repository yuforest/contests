// g++ -o c.out c.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc233/tasks/abc233_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc233/tasks/abc233_c c.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
long long minimum_time = 0;
vector<bool> used(200007, false);
vector<vector<int>> G1(10, vector<int>());
vector<vector<int>> G2(10, vector<int>());
long long K[200007];
long long T[200007];

#include<bits/stdc++.h>
#define mod 998244353
#define inv2 499122177
using namespace std;
long long triangular_number(long long x){
  x%=mod;
  long long res=x;
  res*=(x+1);res%=mod;
  res*=inv2;res%=mod;
  return res;
}

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int main(){
  long long n;
  cin >> n;
  
  long long res=0;
  long long p10=10;
  for(int dg=1;dg<=18;dg++){
    long long l=p10/10;
    long long r=min(n,p10-1);
    if(l<=r){res+=triangular_number(r-l+1);res%=mod;}
    p10*=10;
  }
  
  cout << res << '\n';
  cout << modinv(2, mod) << endl;
  return 0;
}