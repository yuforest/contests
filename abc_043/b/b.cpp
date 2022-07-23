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
	string s;
	cin >> s;
	string ans = "";
	for (auto c: s) {
		if (c == '0') {
			ans.push_back('0');
		} else if (c == '1') {
			ans.push_back('1');
		} else {
			if (ans != "") {
				ans.pop_back();
			}
		}
	}
	cout << ans << endl;
}
