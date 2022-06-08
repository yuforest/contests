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
int INF = 1000000007;

int main()
{
  int N, K;
  cin >> N >> K;
  vector<int> h(N);
  rep(i, N) {
    cin >> h[i];
  }
  sort(h.begin(), h.end());
  int ans = INF;
  rep(i, N) {
    int h_max_index = i + K - 1;
    if (h_max_index >= N) {
      break;
    }
    int h_min = h[i];
    int h_max = h[h_max_index];
    ans = min(ans, h_max - h_min);
  }
  cout << ans << endl;
}