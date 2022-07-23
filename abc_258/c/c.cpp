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
  int N, Q;
	cin >> N >> Q;
	string S;
	cin >> S;
	ll diff = 0;
	rep(i, Q) {
		ll t,x;
		cin >> t >> x;
		if (t == 1) {
			diff += x;
			diff %= N;
		} else {
			x--;
			ll index = x - diff;
			if (index < 0) {
				index = N - abs(index);
			}
			cout << S[index] << endl;
		}
	}
	return 0;
}