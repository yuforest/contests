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

// 別解(0->iとi->Nの辺があるかを1~N-1に対して探す)
// int N, M;
// set<pair<int, int>> E;
// //---------------------------------------------------------------------------------------------------
// string solve() {
//     rep(i, 1, N - 1) {
//         if (E.count({ 0,i }) && E.count({ i, N - 1 })) return "POSSIBLE";
//     }
//     return "IMPOSSIBLE";
// }
// //---------------------------------------------------------------------------------------------------
// void _main() {
//     cin >> N >> M;
//     rep(i, 0, M) {
//         int a, b; cin >> a >> b;
//         a--; b--;
//         E.insert({ a,b });
//         E.insert({ b,a });
//     }

//     cout << solve() << endl;
// }


void dfs(int pos, int transfer_count) {
	used[pos] = true;
  if (transfer_count == 2) return;
	for (int i : G[pos]) {
		dfs(i, transfer_count+1);
	}
}



int main()
{
  int N, M;
  cin >> N >> M;
  int a[N], b[N];
  rep(i, M) {
    cin >> a[i] >> b[i];
    G[a[i]].push_back(b[i]);
    G[b[i]].push_back(a[i]);
  }
  dfs(1, 0);
  if (used[N]) {
    cout << "POSSIBLE" << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
  }
}