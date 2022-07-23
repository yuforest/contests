// g++ -o b.out b.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc216/tasks/abc216_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc216/tasks/abc216_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int b_count = 0;
int N;
vector<int> A;

ll mod = 998244353;
long long modpow(long long a,long long b) {
    long long ans = 1;
    // bが0以上
    while(b) {
      if(b & 1) {
        cout << (b & 1) << endl;
        a *= a;
        a %= mod;
      }
      a *= a;
      a %= mod;
      b /= 2;
    }
    return ans;
}


int main()
{
  ll N;
  cin >> N;
  vector<ll>D(N),E(N);
  rep(i, N) {
    cin >> D[i];
    E[D[i]]++;
  }

  // 0の個数が1ではないまたは、辺1の距離が0ではない
  if(E[0] != 1 || D[0] != 0) {
    cout << 0 << endl;
    return 0;
  }

  int ans = 1;
  for(int i = 1; i < N; i++) {
    // 各頂点の1つ前の頂点の頂点1からの距離
    int before_distance = D[i]-1;
    // cout << before_distance << "->" << E[before_distance] << endl;
    // 1つ前の頂点の個数をかけることで現在の頂点の場合の数を計算する
    ans = (ans * (E[before_distance])) % mod;
  }
  cout << ans << endl;
}