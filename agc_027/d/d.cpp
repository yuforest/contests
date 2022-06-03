// g++ -o c.out c.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc216/tasks/abc216_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc216/tasks/abc216_c c.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;

int main(void)
{
  int N, M;
  cin >> N >> M;
  vector<deque<int>> deqs(M, deque<int>);
  for (int i = 0; i < M; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int ball;
      cin >> ball;
      deqs[i].push_back(ball);
    }
  }
  string ans = "No";
  while (true) {
    bool empty = true;
    vector<int> 
    for (int i = 0; i < M; i++) {
      deque<int> current_deq = deqs[i];
      if (!current_deq.empty()) {
        empty = false;
      }
    }
    if (empty) {
      ans = "Yes";
      break;
    }
  }
  cout << ans << endl;
}