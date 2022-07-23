// g++ -o b.out b.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc226/tasks/abc226_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc226/tasks/abc226_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main()
{
  int N;
  cin >> N;
  vector<int> L(N);
  vector<vector<int>> A(N, vector<int>());
  for (int i = 0; i < N; ++i) {
    int l;
    cin >> l;
    L[i] = l;
    for (int j = 0; j < l; ++j) {
      int a;
      cin >> a;
      A[i].push_back(a);
    }
  }
  vector<string> strings;

  for (int i = 0; i < N; ++i) {
    string S = "";
    for (int k = 0; k < L[i]; ++k) {
      S += to_string(A[i][k]);
      S += " ";
    }
    strings.push_back(S);
  }
  sort(strings.begin(), strings.end());
  strings.erase(unique(strings.begin(), strings.end()), strings.end());
  cout << strings.size() << endl;
}