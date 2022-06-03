// g++ -o c.out c.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc218/tasks/abc218_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc218/tasks/abc218_c c.cpp

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;

vector<vector<int>> G;
bool temp[100007];

int main(void)
{
  int N, M;
  cin >> N >> M;
  dsu G(N);
  for(int i=0;i<M;i++){
    int a, b;
    cin >> a >> b;
    a--;b--;
    G.merge(a, b);
  }
  int ans = G.groups().size()-1;
  cout << ans << endl;
}