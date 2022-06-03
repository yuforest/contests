#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2000;
vector<vector<int>> G;
bool temp[MAX_N];
void dfs(int v)
{
  if (temp[v])
    return;
  temp[v] = true;
  for (auto vv : G[v])
    dfs(vv);
}
int main()
{
  int N, M;
  cin >> N >> M;
  G.resize(N);
  for (int i = 0; i < M; i++)
  {
    int a, b;
    cin >> a >> b;
    G[a - 1].push_back(b - 1);
  }
  int ans = 0;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
      temp[j] = false;
    dfs(i);
    for (int j = 0; j < N; j++)
      if (temp[j])
        ans++;
  }

  cout << ans;
}