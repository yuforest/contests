#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int N, M, Q;
vector<int> a;
vector<int> b;
vector<int> c;
vector<int> d;
int ans;

void dfs(vector<int> A) {
  // スコア計算して最大値更新
  if (A.size() == N+1) {
    int now = 0;
    rep(i, Q) {
      if (A[b[i]] - A[a[i]] == c[i]) now += d[i];
    }
    // cout << now << endl;
    ans = max(ans, now);
    return;
  }
  // 現在の一番最後の値を追加
  A.push_back(A.back());
  // M以下を満たす場合
  while (A.back() <= M) {
    dfs(A);
    // インクリメント
    A.back()++;
  }
}
int main()
{
  cin >> N >> M >> Q;
  a = b = c = d = vector<int>(Q);
  rep(i, Q) {
    cin >> a.at(i) >> b.at(i) >> c.at(i) >> d.at(i);
  }
  // 最初に1が入った長さ1の配列を渡す
  dfs(vector<int>(1, 1));
  cout << ans << endl;
  return 0;
}