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
	int W, H, N;
	cin >> W >> H >> N;
	int X[N], Y[N], A[N];
	rep(i, N) {
		cin >> X[i] >> Y[i] >> A[i];
	}
	// 白い部分の始まりと終わりの座標
	int W_S = 0;
	int W_E = W;
	int H_S = 0;
	int H_E = H;
	rep(i, N) {
		if (A[i] == 1) {
			W_S = max(W_S, X[i]);
		} else if (A[i] == 2) {
			W_E = min(W_E, X[i]);
		} else if (A[i] == 3) {
			H_S = max(H_S, Y[i]);
		} else if (A[i] == 4) {
			H_E = min(H_E, Y[i]);
		}
	}
	int ans = max(0, W_E - W_S) * max(0, H_E - H_S);
	cout << ans << endl;
	return 0;
}
