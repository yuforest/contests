// g++ -o c.out c.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc233/tasks/abc233_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc233/tasks/abc233_c c.cpp


#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
int main() {
  int Q;
  cin >> Q;
  // priority_queue<long long> que;
  // large.top() は large の最小値
  priority_queue<long long, vector<long long>, greater<long long> > que;
  rep1(i, Q) {
    int operation;
    long long x;
    int k;
    cin >> operation;
    cin >> x;
    if (operation == 1) {
      que.push(x);
    } else if (operation == 2) {
      // x以下で大きい方からk番目
      auto it = lower_bound(que.begin(), que.end(), x);
      cin >> k;

    } else if (operation == 3) {
      // x以上で小さい方からk番目
      cin >> k;
    }
  }
  while (!que.empty()) {
    cout << que.top() << endl;
    que.pop();
  }


}