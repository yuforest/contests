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
	int A_index, Z_index;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == 'A') {
			A_index = i;
			break;
		}
	}
	for (int i = S.size()-1; i >= 0; i--) {
		if (S[i] == 'Z') {
			Z_index = i;
			break;
		}
	}
	cout << Z_index - A_index + 1 << endl;
	return 0;
}
