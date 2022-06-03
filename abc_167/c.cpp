#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int N, M, X;
vector<ll> C(13);
vector<vector<int>> A(13, vector<int> (13));
int ans = 30000000;

bool ok = false;
int cnt = 0;
void dfs(vector<int> U)
{
  if (U.size() == N + 1) {
    return;
  }
  int price = 0;
  bool score_ok = true;
  rep(i, U.size()) {
    price += C[i];
    cout << U[i] << endl;
  }
  cout << "--" << endl;
  rep(i, M) {
    int score = 0;
    rep(j, U.size()) {
      score += A[j][i];
    }
    if (score < X) {
      score_ok = false;
      break;
    }
  }
  if (score_ok) {
    ans = min(ans, price);
    ok = true;
  }
  
  while (U.back() < N) {
    dfs(U);
    U.push_back(cnt);
    cnt++;
  }
}

int main() {
  cin >> N >> M >> X;
  rep(i, N) {
    cin >> C[i];
    rep(j, M) {
      cin >> A[i][j];
    }
  }
  dfs(vector<int> ());
  if (ok) {
    cout << ans << endl;
  } else {
    cout << -1 << endl;
  }
  vector<bool> p(N, true);
}