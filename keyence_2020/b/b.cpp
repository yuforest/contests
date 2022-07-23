// g++ -o b.out b.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc216/tasks/abc216_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc216/tasks/abc216_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using pll = pair<long long, long long>;

int main()
{
  int N; cin >> N;
  vector<pll> v(N);
  for (int i = 0; i < N; ++i) {
      long long a, l;
      cin >> a >> l;
      v[i] = {a - l, a + l};
  }

  // 区間を右端の小さい順にソート
  sort(v.begin(), v.end(), [](pll a, pll b) {
    return a.second < b.second;
  });

  // cur := 現在選んでいる区間のうち、最も右にあるやつの右端
  int res = 0;
  long long cur = -(1LL<<60);
  for (int i = 0; i < N; ++i) {
      if (cur > v[i].first) continue; // 被るやつは飛ばす
      ++res;
      // 更新
      cur = v[i].second;
  }
  cout << res << endl;
}
