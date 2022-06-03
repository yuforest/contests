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
	int A, B;
	string S;
	cin >> A >> B >> S;
	string ans = "Yes";
	for (int i = 0; i < S.size(); i++) {
		if (i == A) {
			if (S[i] != '-') {
				ans = "No";
			}
		} else {
			if (!isdigit(static_cast<unsigned char>(S[i]))) {
				ans = "No";
			}
		}
	}
	cout << ans << endl;
}
