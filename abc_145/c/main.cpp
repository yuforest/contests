// g++ -o c.out c.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc226/tasks/abc226_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc226/tasks/abc226_c c.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
long long minimum_time = 0;
vector<bool> used(200007, false);
vector<int> G[1 << 18];
long long K[200007];
long long T[200007];
const int inf = INT_MAX / 2;
const ll infl = 1LL << 60;


int main()
{
  int N;
  cin >> N;
  int x[N];
  int y[N];
  rep(i, N) {
    cin >> x[i] >> y[i];
  }
  double ans = 0;
  vector<int> nums(N);
	iota(nums.begin(), nums.end(), 0);
  double count = 0;
  do {
    // for (auto e: nums) {
    //   cout << e << " ";
    // }
    // cout << endl;
    count++;
    for (int i = 1; i < N; i++) {
      int before = nums[i-1];
      int after = nums[i];
      ans += sqrt(pow(x[before] - x[after], 2) + pow(y[before] - y[after], 2));
      // cout << sqrt(pow(x[before] - x[after], 2) + pow(y[before] - y[after], 2)) << endl;
    }
  } while (next_permutation(nums.begin(), nums.end()));
  ans /= count;
  cout << setprecision(16) << ans << endl;
}