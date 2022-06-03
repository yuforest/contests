// g++ -o c.out c.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc229/tasks/abc229_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc229/tasks/abc229_c c.cpp


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
  ll N, W;
  cin >> N >> W;
  vector<P> cheeses(N);

  rep (i, N) {
    int a, b;
    cin >> a >> b;
    P cheese = make_pair(a, b);
    cheeses[i] = cheese;
  }
  sort(cheeses.begin(), cheeses.end());
  reverse(cheeses.begin(), cheeses.end());
  ll ans = 0;
  for (int i = 0; i < cheeses.size(); i++) {
    long long value = cheeses[i].first * 1LL;
    long long weight = cheeses[i].second * 1LL;
    if (W > weight) {
      W -= weight;
      ans += weight * value * 1LL;
    } else {
      ans += W * value * 1LL;
      W = 0;
      break;
    }
  }
  cout << ans << endl;
}