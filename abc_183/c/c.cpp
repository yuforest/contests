// g++ -o c.out c.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc219/tasks/abc219_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc219/tasks/abc219_c c.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main(void)
{
  int N, K;
  cin >> N >> K;
  vector<vector<int>> times(N, vector<int>(N));
  rep(i, N) {
    rep(j, N) {
      cin >> times[i][j];
    }
  }
  vector<int> v(N-1);
  int v_size = v.size();
  iota(v.begin(), v.end(), 1);
  int ans = 0;
  do {
    int sum = 0;
    sum += times[0][v[0]];
    for(int i = 0; i < v_size; i++) {
      if (i == 0) continue;
      sum += times[v[i-1]][v[i]];
      // cout << v[i] << " "
    }
    sum += times[v[v_size-1]][0];
    if (sum == K) ans++;
		// cout << "\n";								// v の要素を表示
	} while (next_permutation(v.begin(), v.end())); // 次の順列を生成
  cout << ans << endl;
}