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
	char a[H][W];
	rep(i, H) {
		rep (j, W) {
			cin >> a[i][j];
		}
	}
	rep(i, H+2) {
		rep(j, W+2) {
			if (i == 0 || i == H + 1 || j == 0 || j == W + 1) {
				cout << '#';
			} else {
				cout << a[i-1][j-1];
			}
		}
		if (i != H+1) cout << endl;
	}
}
