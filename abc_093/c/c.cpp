// g++ -o c.out c.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc226/tasks/abc226_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc226/tasks/abc226_c c.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
long long minimum_time = 0;
vector<bool> used(200007, false);
vector<int> G[1 << 18];
long long K[200007];
long long T[200007];


int main()
{
  vector<int> nums(3);
  rep(i, 3) {
    cin >> nums[i];
  }
  sort(nums.begin(), nums.end(), greater<int>());
  int diff1 = nums[0] - nums[1];
  int diff2 = nums[0] - nums[2];
  int diff3 = abs(diff1 - diff2);
  int ans = 0;
  ans += min(diff1, diff2);
  ans += diff3 / 2;
  if (diff3 % 2 == 1) {
    ans += 2;
  }
  cout << ans << endl;
}