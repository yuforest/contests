// g++ -o a.out a.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc213/tasks/abc213_a
// oj t
// oj s https://atcoder.jp/contests/abc213/tasks/abc212_a a.cpp

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int N, K;
  cin >> N >> K;
  int A[N];
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  map<int, int> mp;
  for (int i = 0; i < N; i++) {
    mp[A[i]]++;
  }
  vector<pair<int, int>> V;
  for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
    V.push_back({ it->second, it->first });
  }
  sort(V.begin(), V.end());

  int sum = 0;
  int size = V.size();
  for (int i = 0; i < size; i++) {
    if (size - i <= K) break;
    sum += V[i].first;
  }

  cout << sum << endl;
}