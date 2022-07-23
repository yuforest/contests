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

int main()
{
  int N, M;
  cin >> N >> M;
  vector<int> X(M);
  rep(i, M) {
    cin >> X[i];
  }
  sort(X.begin(), X.end());
  // XとX+1の差を取る、差が小さいほど良い
  vector<int> d;
  rep(i, M-1) {
    d.push_back(X[i+1] - X[i]);
  }
  sort(d.begin(), d.end());

  ll ans = 0;
  // NがMより大きい時は0回の移動ですむ
  int cnt = max(0, M - N);
  rep(i, cnt) {
    ans += d[i];
  }
  cout << ans << endl;

}