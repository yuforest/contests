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

void dfs(int pos) {
  minimum_time += T[pos];
	used[pos] = true;

	for (int i : G[pos]) {
		if (used[i] == false) dfs(i);
	}
}

int main()
{
  int N;
  cin >> N;
  int A[N];
  int B[N];
  rep(i, N) {
    cin >> A[i];
  }
  rep(i, N) {
    cin >> B[i];
  }
  int cumulative_A[N];
  int cumulative_B[N];
  for (int i = 0; i < N; i++) {
    if (i == 0) {
      cumulative_A[i] = A[i];
    } else {
      cumulative_A[i] = cumulative_A[i-1] + A[i];
    }
  }
  // cumulative_Bは逆から累積を計算する
  for (int i = N-1; i >= 0; i--) {
    if (i == N-1) {
      cumulative_B[i] = B[i];
    } else {
      cumulative_B[i] = cumulative_B[i+1] + B[i];
    }
  }
  int ans = 0;
  rep(i, N) {
    ans = max(ans, cumulative_A[i] + cumulative_B[i]);
  }
  cout << ans << endl;
}