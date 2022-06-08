// g++ -o b.out b.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc226/tasks/abc226_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc226/tasks/abc226_b b.cpp


#include <bits/stdc++.h>
#include <tuple>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
// using P = pair<int, int>;


int N;
string S[101];
int P[101];
int main() {
	cin >> N;
	rep(i, N) cin >> S[i] >> P[i];

	vector<int> ans;
	rep(i, N) ans.push_back(i);
	sort(ans.begin(), ans.end(), [&](int a, int b) {
		if (S[a] != S[b]) return S[a] < S[b];
		return P[a] > P[b];
	});

	rep(i, ans.size()) cout << ans[i] + 1 << endl;
}
