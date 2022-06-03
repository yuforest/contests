// g++ -o c.out c.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc222/tasks/abc222_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc222/tasks/abc222_c c.cpp


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
  for (int i = 1; i <= 2 * N; i++) {
    rank[i] = i;
    mp[i] = -1;
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
        if (mp[first] == -1) {
          mp[first] = 0;
        }
        mp[first]++;
        continue;
      }
      if (
        first_hand == 'C' && second_hand == 'G' ||
        first_hand == 'G' && second_hand == 'P' ||
        first_hand == 'P' && second_hand == 'C'
      ) {
        if (mp[second] == -1) {
          mp[second] = 0;
        }
        mp[second]++;
        continue;
      }
    }
    vector<pair<int, int>> V;
    for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
      V.push_back({ it->second * -1, it->first });
    }
    sort(V.begin(), V.end());
    for (int i = 1; i <= 2 * N; i++) {
      rank[i] = V[i-1].second;
    }
  }
  for (int i = 1; i <= 2 * N; i++) {
    cout << rank[i] << endl;
  }
}