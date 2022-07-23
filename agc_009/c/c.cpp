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
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> T[i];
    long long k;
    cin >> k;
    K[i] = k;
    for (int j = 0; j < K[i]; ++j) {
      int a;
      cin >> a;
      G[i].push_back(a-1);
    }
  }
  dfs(N-1);
  cout << minimum_time << endl;
}