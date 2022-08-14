// g++ -o d.out d.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc174/tasks/abc174_d
// oj t -c "./d.out"
// oj s https://atcoder.jp/contests/abc174/tasks/abc174_d d.cpp

#include <bits/stdc++.h>
using namespace std;
int c[300005];
map<int, int> mp;
// long long mod = 1000000007;
// 縦軸が弁当の種類、横軸がたこ焼きの数、配列の値が鯛焼きの数
int dp[301][301][301];
vector<int> G[1 << 18];

#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;
int n;
string s;
using ll = long long;
int main()
{
  int N, M;
  cin >> N >> M;
  int A[M], B[M];
  rep(i, M) {
    cin >> A[i] >> B[i];
    G[A[i]].push_back(B[i]);
    G[B[i]].push_back(A[i]);
  }
  vector<bool> visited(N+1, false);
  visited[1] = true;
  queue<int> que;
  que.push(1);
  int ans[N+1];
  while(!que.empty()) {
    int now = que.front();
    que.pop();
    for(auto to: G[now]) {
      if (!visited[to]) {
        visited[to] = true;
        ans[to] = now;
        que.push(to);
      }
    }
  }
  cout << "Yes" << endl;
  for(int i = 2; i <= N; i++) {
    cout << ans[i] << endl;
  }
}
