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
	int A, B, C;
	cin >> A >> B >> C;
	string ans = "NO";
	for (int i = 1; i <= B; i++) {
		if (A * i % B == C) {
			ans = "YES";
		}
	}
	cout << ans << endl;
	return 0;
}
