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
  ll N;
  cin >> N;
  map<char, ll> mp;
  rep (i, N) {
    string val;
    cin >> val;
    mp[val[0]]++;
  }
  string march = "MARCH";
  ll ans = 0;
  for (int i = 0; i < 5; i++) {
     for (int j = i+1; j < 5; j++) {
       for (int k = j+1; k < 5; k++) {
        ans += mp[march[i]] * mp[march[j]] * mp[march[k]];
       }
     }
  }
  cout << ans << endl;
}