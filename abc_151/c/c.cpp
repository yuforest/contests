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
  int H, W, K;
  cin >> H >> W >> K;
  string C[H];
  rep(i, H) {
    cin >> C[i];
  }
  int ans = 0;
  for (int h = 0; h < (1<<H); ++h) {
    for (int w = 0; w < (1<<W); ++w) {
      int count = 0;
      for (int i = 0; i < H; ++i) {
        if (h & (1<<i)) continue;
        for (int j = 0; j < W; ++j) {
          if (w & (1<<j)) continue;
          if (C[i][j] == '#') count++;
        }
      }
      if (count == K) ans++;
    }
  }
  cout << ans << endl;
}