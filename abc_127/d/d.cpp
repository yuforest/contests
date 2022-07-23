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

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
using pll = pair<long long, long long>;

// int main() {
//   int N, M; cin >> N >> M;
//   vector<long long> A(N), B(M), C(M);
//   for (int i = 0; i < N; ++i) cin >> A[i];
//   sort(A.begin(), A.end());
//   B.resize(M);
//   C.resize(M);
//   for (int i = 0; i < M; ++i) cin >> B[i] >> C[i];

//   // C をソート (B をまとめて)
//   vector<int> id(M);
//   iota(id.begin(), id.end(), 0);
//   sort(id.begin(), id.end(), [&](int i, int j) {
//           return C[i] > C[j];});

//   // A (小さい順) と C (大きい順) とを比べて大きい方を足していく
//   long long sum = 0;
//   long long K = 0;
//   for (auto i : id) {
//     for (int j = 0; j < B[i]; ++j) {
//       if (K >= N) break;
//       sum += max(A[K++], C[i]);
//     }
//   }

//   for (int i = K; i < N; ++i) sum += A[i];
//   cout << sum << endl;
// }


int main() {
  int N, M; cin >> N >> M;
  vector<pll> v;
  for (int i = 0; i < N; ++i) {
    int a; cin >> a;
    v.push_back({a, 1});
  }
  for (int i = 0; i < M; ++i) {
    int b, c; cin >> b >> c;
    v.push_back({c, b});
  }
  sort(v.begin(), v.end(), greater<pll>());

  long long num = 0;
  long long res = 0;
  for (auto p : v) {
    if (num + p.second <= N) {
      res += p.first * p.second;
      num += p.second;
    }
    else {
      res += p.first * (N - num);
      num = N;
      break;
    }
  }
  cout << res << endl;
}