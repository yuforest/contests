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
vector<int> G[1 << 18];
vector<bool> used(2007, false);
using ll = long long;
ll ans = 0;
ll sum = 0;

void dfs(int pos) {
	used[pos] = true;
  sum++;

	for (int i : G[pos]) {
		if (used[i] == false) dfs(i);
	}
}

int main(void)
{
  int N, M;
  cin >> N >> M;
  int A[M], B[M];
  rep(i, M) {
    cin >> A[i] >> B[i];
    G[A[i]].push_back(B[i]);
  }
  ll ans = 0;
  for(int i = 1; i <= N; i++) {
    dfs(i);
    ans += sum;
    sum = 0;
    used = vector<bool>(2007, false);
  }
  cout << ans << endl;
}