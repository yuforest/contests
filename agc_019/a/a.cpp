// g++ -o a.out a.cpp -std=c++17
// oj d https://atcoder.jp/contests/agc_012/tasks/agc_012_a
// oj t -c "./a.out"
// oj s https://atcoder.jp/contests/agc_012/tasks/agc_012_a a.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;
using ll = long long;

int main(void)
{
   ll Q, H, S, D, N;
	 cin >> Q >> H >> S >> D >> N;
	 ll Q_1l = Q * 4;
	 ll H_1l = H * 2;
	 ll for_1l;
	 for_1l = min({Q_1l, H_1l, S});
	 ll ans1 = N * for_1l;
	 ll ans2 = (N / 2) * D + (N % 2) * for_1l;
	 ll ans = min(ans1, ans2);
	 cout << ans << endl;
}