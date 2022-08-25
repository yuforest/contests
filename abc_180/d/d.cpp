// g++ -o d.out d.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc186/tasks/abc186_d
// oj t -c "./d.out"
// oj s https://atcoder.jp/contests/abc186/tasks/abc186_d d.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
#define rep(i, n) for (int i = 0; i < (n); ++i)
long long mod = 1000000007;

int main() {
  long long N, M;
  cin >> N >> M;
  vector<long long> A(M);
  for (int i = 0; i < M; ++i) cin >> A[i];
  sort(A.begin(), A.end());

  // 番兵追加
  A.insert(A.begin(), 0);
  A.push_back(N+1);

  // 白塊に分解 (同時に最小値も求める)
  vector<long long> v;
  long long K = N;
  for (int i = 0; i+1 < A.size(); ++i) {
      long long len = A[i+1] - A[i] - 1;
      if (len > 0) {
          v.push_back(len);
          K = min(K, len);
      }
  }

  long long res = 0;
  for (auto len : v) res += (len + K - 1) / K;
  cout << res << endl;
}