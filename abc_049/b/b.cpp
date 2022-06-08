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
	int H, W;
	cin >> H >> W;
	string C[H];
	rep(i, H) {
		cin >> C[i];
	}
	rep (i, H) {
		cout << C[i] << endl;
		cout << C[i] << endl;
	}
}
