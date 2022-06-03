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
	string S;
	cin >> S;
	map<char, int> mp;
	for (auto c: S) {
		mp[c]++;
	}
	for (auto e: mp) {
		if (e.second > 1) {
			cout << "no" << endl;
			return 0;
		}
	}
	cout << "yes" << endl;
	return 0;
}
