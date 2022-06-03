#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
#define rep_ex(i, n) for (int i = 0; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int N, M;
  cin >> N >> M;
  int A[N], B[N], C[M], D[M];

  for (int i = 0; i < N; ++i) {
    cin >> A[i] >> B[i];
  }
  for (int i = 0; i < M; ++i) {
    cin >> C[i] >> D[i];
  }
  for (int i = 0; i < N; ++i) {
    int distance = 1000000007;
    int checkpoint;
    for (int j = 0; j < M; ++j) {
      int current_distance = abs(A[i] - C[j]) + abs(B[i] - D[j]);
      // cout << A[i] << " " << B[i] << " " << C[j] << " " << D[j] << endl;
      // cout << current_distance << endl;
      if (distance > current_distance) {
        distance = current_distance;
        checkpoint = j + 1;
      }
    }
    cout << checkpoint << endl;
  }
}