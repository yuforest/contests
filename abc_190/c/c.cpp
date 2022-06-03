// g++ -o c.out c.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc190/tasks/abc190_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc190/tasks/abc190_c c.cpp


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
  bool putted[N+1];
  for (int i = 0; i < N+1; ++i) {
    putted[i] = false;
  }
  int A[M], B[M];
  rep (i, M) {
    cin >> A[i];
    cin >> B[i];
  }
  int K;
  cin >> K;
  int C[K], D[K];
  rep (i, K) {
    cin >> C[i];
    cin >> D[i];
  }

  int count = 0;

  for (int bit = 0; bit < (1<<K); ++bit) {
    vector<int> S;
    int tmp_count = 0;
    for (int i = 0; i < K; ++i) {
      if (bit & (1<<i)) {
        S.push_back(C[i]);
        putted[C[i]] = true;
      } else {
        S.push_back(D[i]);
        putted[D[i]] = true;
      }
    }

    for (int i = 0; i < M; ++i) {
      if (putted[A[i]] && putted[B[i]]) tmp_count++;
    }

    count  = max(count, tmp_count);

    for (int i = 0; i < N+1; ++i) {
      putted[i] = false;
    }
  }
  cout << count << endl;
}