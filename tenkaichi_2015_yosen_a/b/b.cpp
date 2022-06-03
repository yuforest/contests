// g++ -o b.out b.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc216/tasks/abc216_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc216/tasks/abc216_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int N, M;
  cin >> N >> M;
  int A[N];
  rep (i, N) {
    cin >> A[i];
  }

  vector<int> count(M+1, 0);

  rep (i, N) {
    count[A[i]]++;
  }

  int max = max_element(count.begin(), count.end()) - count.begin();
  int max_count = *max_element(count.begin(), count.end());

  if (max_count > N / 2) {
    cout << max << endl;
  } else {
    cout << "?" << endl;
  }
}