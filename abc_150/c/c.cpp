// g++ -o c.out c.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc218/tasks/abc218_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc218/tasks/abc218_c c.cpp

#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[300005];
map<int, int> mp;
long long mod = 1000000007;

int main(void)
{
  int N;
  cin >> N;
  vector<int> P(N);
  vector<int> Q(N);
  for (int i = 0; i < N; i++) {
    cin >> P[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> Q[i];
  }
  vector<int> sorted = P;
  sort(sorted.begin(), sorted.end());

  int p_order, q_order;
  int count = 1;
  do {
    bool is_p = true;
    bool is_q = true;
    for (int i = 0; i < N; i++) {
      if (sorted[i] != P[i]) is_p = false;
      if (sorted[i] != Q[i]) is_q = false;
    }
    if (is_p) p_order = count;
    if (is_q) q_order = count;
    count++;
	} while (next_permutation(sorted.begin(), sorted.end()));

  cout << abs(p_order - q_order) << endl;
}