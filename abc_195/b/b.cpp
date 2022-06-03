// g++ -o b.out b.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc226/tasks/abc226_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc226/tasks/abc226_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(){
  int a,b,w;
  cin >> a >> b >> w;
  int m=1e9,M=0;
  for(int n=1;n<=1000000;n++){
    if(a*n<=1000*w && 1000*w<=b*n){
      m=min(m,n);
      M=max(M,n);
    }
  }
  if(M==0)cout << "UNSATISFIABLE";
  else cout << m << ' ' << M;
}