// g++ -o c.out c.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc233/tasks/abc233_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc233/tasks/abc233_c c.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
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

int N;
ll X;
int L[100007];
vector<vector<ll>> a(100007, vector<ll>());
ll ans = 0;

int main() {
  ll N, M;
  cin >> N >> M;
  ll A[N];
  ll B[N];
  rep(i, N) {
    cin >> A[i] >> B[i];
  }
  vector<int> S;
  for (int i = 0; i < N; i++) {
    S.push_back(i);
  }
  sort(S.begin(), S.end(), [&](int left, int right){
    return A[left] < A[right];
  });
  // sort(ans.begin(), ans.end(), [&](int a, int b) {
	// 	if (S[a] != S[b]) return S[a] < S[b];
	// 	return P[a] > P[b];
	// });
  ll ans = 0;
  for(auto i: S) {
    if (M == 0) break;
    ll purchase_count = min(M, B[i]);
    M -= purchase_count;
    ans += purchase_count * A[i];
  }
  cout << ans << endl;
  return 0;
}
