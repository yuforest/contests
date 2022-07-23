// g++ -o b.out b.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc219/tasks/abc219_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc219/tasks/abc219_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
long long mod = 1000000007;

int main() {
	int N, M;
	cin >> N >> M;
	string A[N];
	string B[M];
	rep(i, N) {
		cin >> A[i];
	}
	rep(i, M) {
		cin >> B[i];
	}
	string ans = "No";
	rep(i, N-M+1) {
		rep(j, N-M+1) {
			bool ok = true;
			rep(k, M) {
				rep(l, M) {
					if (A[i+k][j+l] != B[k][l] ) ok = false;
				}
			}
			if (ok) ans = "Yes";
		}
	}
	cout << ans << endl;
}
