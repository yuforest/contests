// g++ -o c.out c.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc226/tasks/abc226_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc226/tasks/abc226_c c.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
long long minimum_time = 0;
vector<bool> used(200007, false);
vector<int> G[1 << 18];
long long K[200007];
long long T[200007];

// 別解
// int main(){
//   int n;
//   long long X=0,x=0,ans=1000000000000000000LL;
//   cin>>n;
//   vector<long long> a(n);
//   for(int i=0;i<n;i++){
//     cin>>a[i];
//     X+=a[i];
//   }
//   for(int i=0;i<n;i++){
//     x+=a[i];
//     if(i+1<n)ans=min(ans,abs(X-2*x));
//   }
//   cout<<ans<<endl;
// }

int main()
{
  int N;
  cin >> N;
  ll A[N];
  ll sum = 0;
  rep(i, N) {
    cin >> A[i];
    sum += A[i];
  }
  ll cumulative[N];
  cumulative[0] = A[0];
  for (int i = 1; i < N-1; i++) {
    cumulative[i] = cumulative[i-1] + A[i];
  }
  ll ans = pow(10, 17);
  rep(i, N-1) {
    ll x = cumulative[i];
    ll y = sum - x;
    ll tmp = abs(x - y);
    ans = min(ans, tmp);
  }
  cout << ans << endl;

  return 0;
}