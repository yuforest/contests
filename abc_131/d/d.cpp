// g++ -o d.out d.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc219/tasks/abc219_d
// oj t -c "./d.out"
// oj s https://atcoder.jp/contests/abc219/tasks/abc219_d d.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;
// 縦軸が弁当の種類、横軸がたこ焼きの数、配列の値が鯛焼きの数
int dp[301][301][301];
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;


// 別解
// string solve() {
// 	vector<int> ord;
// 	rep(i, N) ord.push_back(i);
// 	sort(ord.begin(), ord.end(), [&](int a, int b) { return B[a] < B[b]; });

// 	int t = 0;
// 	rep(i, 0, N) {
// 		int a = A[ord[i]];
// 		int b = B[ord[i]];

// 		t += a;
// 		if (b < t) return "No";
// 	}

// 	return "Yes";
// }

int main(void)
{
  ll N;
  cin >> N;
  ll A[N], B[N];
  rep(i, N) {
    cin >> A[i] >> B[i];
  }
  vector<pair<ll, ll>> works;
  // B[i], A[i]の順番のpairのvectorを作成
  rep(i, N) {
    pair<ll, ll> tmp = { B[i], A[i] };
    works.push_back(tmp);
  }
  // 締切の昇順にソート
  sort(works.begin(), works.end());
  ll current = 0;
  rep(i, N) {
    current += works[i].second;
    // 仕事が終わった時に締切を過ぎたらダメ
    if (current > works[i].first) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}