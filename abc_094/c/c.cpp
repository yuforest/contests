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
  int X[N];
  int A[N];
  rep(i, N) cin >> X[i];
  rep(i, N) A[i] = X[i];
  // 昇順に並べたもの
  sort(A, A + N);

  // 昇順に並べた時に特定の数字が最も早く現れるインデックス
  map<int, int> idx;
  for (int i = N-1; i >= 0; i--) {
    idx[A[i]] = i;
  }
  rep(i, N) {
    int j = idx[X[i]];
    // インデックスが半分以下の位置にあればA[N / 2]が答え
    if (j < N / 2) {
      cout << A[N / 2] << endl;
    } else {
      cout << A[N / 2 - 1] << endl;
    }
  }
}