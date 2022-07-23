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
	map<char, string> mp;
	cin >> mp['a'];
	cin >> mp['b'];
	cin >> mp['c'];
	char ans;
	char current = 'a';
	while(true) {
		if (mp[current].empty()) {
			ans = current - ('a' - 'A');
			break;
		}
		char tmp = mp[current][0];
		mp[current].erase(0,1);
		current = tmp;
	}
	cout << ans << endl;
	return 0;
}
