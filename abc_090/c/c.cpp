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
  vector<vector<int>> c(3, vector<int>(3));
  rep (i, 3) {
    rep (j, 3) {
      cin >> c[i][j];
    }
  }
  bool flag = true;

  for(int i = 0;i<=1;i++) {
    flag &= (c[i][0] - c[i][1] == c[i+1][0] - c[i+1][1]);
    flag &= (c[i][1]-c[i][2] == c[i+1][1]-c[i+1][2]);
    flag &= (c[0][i]-c[1][i] == c[0][i+1]-c[1][i+1]);
    flag &= (c[1][i]-c[2][i] == c[1][i+1]-c[2][i+1]);
  }
  cout<<(flag?"Yes":"No") << endl;
}