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
using namespace std;

ll MAX = 1 << 18;

#define rep(i,l,r) for(ll i=l;i<=r;i++)

int N;
ll X;
int L[100007];
vector<vector<ll>> a(100007, vector<ll>());
ll ans = 0;


int main() {
  ll n,k;cin>>n>>k;
    vector<ll>a(n);
    rep(i,0,n-1) cin>>a[i];
    vector<ll>s(n+1);
    rep(i,0,n-1)s[i+1]=s[i]+a[i];
    map<ll,ll>mp;
    ll ans=0;
    rep(r,1,n){
        mp[s[r-1]]++;
        ans += mp[s[r]-k];
    }
    cout<<ans<<endl;
    return 0;
}


