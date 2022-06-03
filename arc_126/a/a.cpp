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
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y; cin >> x >> y;
		X.push_back({ x, i });
		Y.push_back({ y, i });
	}
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	map<P, int>p;
	p[{X[0].second, X[N - 1].second}] = max(p[{X[0].second, X[N - 1].second}], f(0, N - 1, 0));
	p[{X[0].second, X[N - 2].second}] = max(p[{X[0].second, X[N - 2].second}], f(0, N - 2, 0));
	p[{X[1].second, X[N - 1].second}] = max(p[{X[1].second, X[N - 1].second}], f(1, N - 1, 0));
	p[{Y[0].second, Y[N - 1].second}] = max(p[{Y[0].second, Y[N - 1].second}], f(0, N - 1, 1));
	p[{Y[0].second, Y[N - 2].second}] = max(p[{Y[0].second, Y[N - 2].second}], f(0, N - 2, 1));
	p[{Y[1].second, Y[N - 1].second}] = max(p[{Y[1].second, Y[N - 1].second}], f(1, N - 1, 1));
	vector<int>v;
	for (auto x : p) {
		v.push_back(x.second);
	}
	sort(v.rbegin(), v.rend());
	cout << v[1] << endl;
	return 0;

}

