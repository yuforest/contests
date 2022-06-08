// g++ -o a.out a.cpp -std=c++17
// oj d https://atcoder.jp/contests/agc_012/tasks/agc_012_a
// oj t -c "./a.out"
// oj s https://atcoder.jp/contests/agc_012/tasks/agc_012_a a.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;

int main(void)
{
  string s;
	cin >> s;
	int ans = 0;
	for (char& c: s) {
		ans += c - '0';
	}
	ans = max(ans, (9 * ((int)s.size() - 1) + s.front() - '1'));
	cout << ans << endl;
}