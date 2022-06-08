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
	int N;
	cin >> N;
	string W[N];
	map<string, int> mp;
	rep(i, N) {
		cin >> W[i];
		mp[W[i]]++;
	}
	string ans = "Yes";
	for (auto e: mp) {
		if (e.second > 1) {
			ans = "No";
		}
	}
	for (int i = 1; i < N; i++) {
		if (W[i][0] != W[i-1][W[i-1].size()-1]) {
			ans = "No";
		}
	}
	cout << ans << endl;
	return 0;

}
