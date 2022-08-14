// g++ -o b.out b.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc219/tasks/abc219_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc219/tasks/abc219_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
vector<int> G[1 << 18];

int main()
{
  int N, M;
  cin >> N >> M;
  int u[M], v[M];
  map<string, int> mp;
  rep(i, M) {
    cin >> u[i] >> v[i];
    string key = "";
    key += ('0' + u[i]);
    key += ('0' + v[i]);
    mp[key]++;
  }
  vector<int> ord;
	rep(i, M) ord.push_back(i);
	sort(ord.begin(), ord.end(), [&](int a, int b) {
    if (u[a] != u[b]) {
      return u[a] < u[b];
    } else {
      return v[a] < v[b];
    }
  });
  // for(int i = 0; i < M; i++) {
  //   cout << ord[i] << endl;
  // }
  // cout << u[0] << endl;
  // cout << v[0] << endl;
  int ans = 0;
  for(int i = 0; i < M; i++) {
    for(int j = i+1; j < M; j++) {
      int first = ord[i];
      int second = ord[j];
      if (u[first] == u[second]) {
        string key = "";
        key += ('0' + v[first]);
        key += ('0' + v[second]);
        // cout << key << endl;
        if (mp[key] > 0) {
          ans++;
        }
      }
      // for(int k = j+1; k < M; k++) {
      //   int first = ord[i];
      //   int second = ord[j];
      //   int third = ord[k];
      //   if (u[first] == u[second] && v[first] == u[third] && v[second] == v[third]) {
      //     ans++;
      //   }
      // }
    }
  }
  cout << ans << endl;
}