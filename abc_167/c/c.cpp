// g++ -o c.out c.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc226/tasks/abc226_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc226/tasks/abc226_c c.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
long long minimum_time = 0;
vector<bool> used(200007, false);
vector<int> G[1 << 18];
long long K[200007];
long long T[200007];
const int inf = INT_MAX / 2;
const ll infl = 1LL << 60;


int main()
{
  int N, M, X;
  cin >> N >> M >> X;
  int C[N];
  int A[N][M];

  for(int i = 0; i < N; i++) {
    cin >> C[i];
    for(int j = 0; j < M; j++) {
      cin >> A[i][j];
    }
  }
  int ans = INT_MAX;
  // どの本を買ったか、買わなかったかをbit全探索
  rep(bit, 1 << N) {
    int sum = 0;
    vector<int> comprehension(M, 0);
    rep(i, N) {
      // これがtrueになっているということは本を買ったということ
      if (bit & (1 << i)) {
        sum += C[i];
        rep(j, M) {
          comprehension[j] += A[i][j];
        }
      }
    }

    bool ok = true;
    rep(i, M) {
      if (comprehension[i] < X) ok = false;
    }
    if (ok) ans = min(ans, sum);
  }
  if (ans == INT_MAX) {
    ans = -1;
  }
  cout << ans << endl;
}