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
	string A, B;
	cin >> A >> B;
	int A_length = A.size();
	int B_length = B.size();
	if (A_length > B_length) {
		cout << "GREATER" << endl;
		return 0;
	}
	if (A_length < B_length) {
		cout << "LESS" << endl;
		return 0;
	}
	for (int i = 0; i < A_length; i++) {
		int A_digit = A[i] - '0';
		int B_digit = B[i] - '0';
		if (A_digit > B_digit) {
			cout << "GREATER" << endl;
		  return 0;
		}
		if (A_digit < B_digit) {
			cout << "LESS" << endl;
		  return 0;
		}
	}
	cout << "EQUAL" << endl;
	return 0;
}
