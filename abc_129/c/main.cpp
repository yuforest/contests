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

ll mod = 1000000007;

int main() {
  int N, M;
  cin >> N >> M;
  int a[N];
  map<int, bool> broken;
  rep(i, M) {
    cin >> a[i];
    broken[a[i]] = true;
  }
  vector<ll> dp(N+1, 0);
  dp[0] = 1;
  for (int i = 0; i < N; i++) {
    dp[i] %= mod;

    if (broken[i]) continue;

    // 1段昇る場合
    dp[i+1] += dp[i];
    // 2段昇る場合
    if (i < N-1) {
      dp[i+2] += dp[i];
    }
  }
  cout << dp[N] % mod << endl;
}
