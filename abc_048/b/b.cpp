// g++ -o b.out b.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc219/tasks/abc219_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc219/tasks/abc219_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
	ll a, b, x;
	cin >> a >> b >> x;
	ll ans;
	ll a_count = max(0LL, a-1) / x;
	ll b_count = b / x;
	ans = b_count - a_count;
	if (a == 0) ans++;

	cout << ans << endl;
}
