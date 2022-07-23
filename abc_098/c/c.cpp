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
  int N;
  cin >> N;
  string S;
  cin >> S;

  int c = 0;
  // 西を向いている人の数を左から右に数えた累積和
  int west[N];
  for (int i = 0; i < N; i++) {
    if (S[i] == 'W') c++;
    west[i] = c;
  }
  // 東を向いている人の数を右から左に数えた累積和
  int east[N];
  c = 0;
  for (int i = N-1; i >= 0; i--) {
    if (S[i] == 'E') c++;
    east[i] = c;
  }

  int ans = 300007;
  rep(i, N) {
    int tmp = 0;
    if (i > 0) tmp += west[i-1];
    if (i < N-1) tmp += east[i+1];
    ans = min(ans, tmp);
  }
  cout << ans << endl;
}