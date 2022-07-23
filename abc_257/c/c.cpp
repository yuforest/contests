// g++ -o c.out c.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc256/tasks/abc256_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc256/tasks/abc256_c c.cpp

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
map<int, int> mp;

int h[3];
int w[3];


int main(){
  int n, x, ans;
	string s;
	vector<pair<int, char> >a;
	cin >> n;
	cin >> s;
	ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> x;
		a.push_back({ x,s[i] });
		if (s[i] == '1')ans++;
	}
  // 体重軽い順にソート
	sort(a.begin(), a.end());
	x = ans;
	for (int i = 0; i < n; i++) {
		if (a[i].second == '1')x--;
		else x++;
		if (i < (n - 1)) {
			if (a[i].first != a[i + 1].first)ans = max(ans, x);
		}
		else ans = max(ans, x);
	}
	cout << ans << endl;
	return 0;
}