// g++ -o a.out a.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc217/tasks/abc217_a
// oj t
// oj s https://atcoder.jp/contests/abc217/tasks/abc217_a a.cpp

#include "bits/stdc++.h"
#define int long long
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll INF = (1LL << 61);
ll mod = 1000000007;
int N;
vector<P>X, Y;

int f(int i, int j, int t) {
	if (t == 0) {
		return abs(X[i].first - X[j].first);
	}
	else {
		return abs(Y[i].first - Y[j].first);
	}
}

signed main() {
	int N;
	cin >> N;
	string digits;
	int M = 0;
	while(N > 0) {
		for (int i = 4; i >= 1; i--) {
			if (N >= i) {
				N -= i;
				M += 2 * i;
				digits.push_back(i + '0');
				break;
			}
		}
	}
	sort(digits.begin(), digits.end());
	cout << M << endl;
	cout << digits << endl;
	return 0;

}

