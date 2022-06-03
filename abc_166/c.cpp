#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N, M;
  cin >> N >> M;
  vector<ll> H(N);
  rep(i, N) {
    cin >> H[i];
  }
  vector<ll> A(M);
  vector<ll> B(M);
  rep(i, M) {
    cin >> A[i];
    cin >> B[i];
  }
  vector<bool> p(N, true);

  rep(j, M){
    if (H[B[j] - 1] > H[A[j] - 1]) {
      p.at(A[j]-1) = false;
    }
    if (H[B[j] - 1] < H[A[j] - 1])
    {
      p.at(B[j] - 1) = false;
    }
      if (H[B[j] - 1] == H[A[j] - 1])
      {
        p.at(A[j] - 1) = false;
        p.at(B[j] - 1) = false;
      }
    }
  int ans = 0;
  rep(i, N) {
    if (p[i] == true) {
      ans++;
    }
  }
  cout << ans << endl;
}
