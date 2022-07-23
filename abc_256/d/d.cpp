// g++ -o c.out c.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc233/tasks/abc233_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc233/tasks/abc233_c c.cpp


#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
int main() {
  int N;
  cin >> N;
  vector<int> L(N);
  vector<int> R(N);
  rep(i, N) {
    cin >> L[i] >> R[i];
  }
  sort(L.begin(), L.end());
  sort(R.begin(), R.end());
  vector <pair<int, int>> ans;
  int current_first = -1;
  for (int i = 0; i < N; i++) {
    if (current_first == -1) {
      current_first = L[i];
    }
    auto it = lower_bound(R.begin(), R.end(), L[i]);
    int index = it - R.begin();
    if (i < N-1 && L[i+1] <= R[i]) {
    } else {
      pair<int, int> tmp = {current_first, R[i]};
      ans.push_back(tmp);
      current_first = -1;
    }
  }
  rep(i, ans.size()) {
    cout << ans[i].first << " " << ans[i].second << endl;
  }
}