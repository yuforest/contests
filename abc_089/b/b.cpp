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
  char S[N];
  map<int, int> mp;
  rep(i, N) {
    cin >> S[i];
    mp[S[i]]++;
  }
  if (mp.size() == 3) {
    cout << "Three" << endl;
  } else if (mp.size() == 4) {
    cout << "Four" << endl;
  }
}