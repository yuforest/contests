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
	string alphabets = "abcdefghijklmnopqrstuvwxyz";
	for (auto c: alphabets) {
		if (mp[c] == 0) {
			cout << c << endl;
			return 0;
		}
	}
	cout << "None" << endl;
	return 0;
}
