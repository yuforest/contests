// g++ -o b.out b.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc222/tasks/abc222_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc222/tasks/abc222_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int N, M;
  cin >> N >> M;
  string A[2*N+1];
  for (int i = 1; i <= 2*N; i++) {
    cin >> A[i];
  }
  map<int, int> mp;
  vector<int> rank(2 * N + 1);
  for (int i = 1; i <= N; i++) {
    rank[i] = i;
  }
  for (int i = 0; i < M; i++) {
    for (int j = 1; j <= N; j++) {
      int first = rank[2 * j];
      int second = rank[2 * j - 1];
      char first_hand = A[first][i];
      char second_hand = A[second][i];
      if (first_hand == second_hand) continue;
      if (
        first_hand == 'G' && second_hand == 'C' ||
        first_hand == 'P' && second_hand == 'G' ||
        first_hand == 'C' && second_hand == 'P'
      ) {
        mp[first]++;
        continue;
      }
      if (
        first_hand == 'C' && second_hand == 'G' ||
        first_hand == 'G' && second_hand == 'P' ||
        first_hand == 'P' && second_hand == 'C'
      ) {
        mp[second]++;
        continue;
      }
      vector<pair<int, int>> V;
      for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
        V.push_back({ it->second, it->first });
      }
      sort(V.begin(), V.end());
      for (int i = 0; i <= N; i++) {
        rank[i+1] = V[i].second;
        cout << V[i].second << endl;
      }
    }
  }
}