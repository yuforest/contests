// g++ -o c.out c.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc233/tasks/abc233_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc233/tasks/abc233_c c.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
long long minimum_time = 0;
vector<bool> used(200007, false);
vector<vector<int>> G1(10, vector<int>());
vector<vector<int>> G2(10, vector<int>());
long long K[200007];
long long T[200007];
#include <bits/stdc++.h>
using namespace std;

ll MAX = 1 << 18;

int N;
ll X;
int L[100007];
vector<vector<ll>> a(100007, vector<ll>());
ll ans = 0;

// greatest common divisor
ll gcd(ll a, ll b) { return a ? gcd(b % a, a) : b; }
// least common multiple
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main() {
	ll a, b, c, d;
	cin >> a >> b >> c >> d;

	ll all = b - a + 1;
	ll Ccnt = (b / c) - ((a-1) / c);
	ll Dcnt = (b / d) - ((a-1) / d);
	ll CDcnt = (b / lcm(c, d)) - ((a-1) / lcm(c, d));
	cout << all - Ccnt - Dcnt + CDcnt << endl;
}