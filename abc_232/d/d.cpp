#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;


int main(){
  int n,m;
  cin >> n >> m;
  vector<int>d(n);
  dsu uf(n);
  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    a--,b--;
    if(uf.same(a,b)){
      cout << "No" << endl;
      return 0;
    }
    uf.merge(a,b);
    d[a]++;
    d[b]++;
  }
  for(int i=0;i<n;i++)if(d[i]>2){
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
}