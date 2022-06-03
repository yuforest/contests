// g++ -o c.out c.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc231/tasks/abc231_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc231/tasks/abc231_c c.cpp


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
  int N, Q;
  cin >> N >> Q;
  vector<int> A(N);
  rep (i, N) {
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  rep (i, Q) {
    int x;
    cin >> x;
    auto position = lower_bound(A.begin(), A.end(), x);
    int index = distance(A.begin(), position);
    cout << N - index << endl;
  }
}