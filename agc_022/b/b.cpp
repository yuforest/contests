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
  int N;
  cin >> N;
  string S[N];
  string T[N];
  map<string, int> mp;

  for (int i = 0; i < N; i++) {
    cin >> S[i];
    cin >> T[i];
    string name = S[i] + " " + T[i];
    auto itr = mp.find(name);
    if( itr != mp.end() ) {
      mp[name]++;
    } else {
      mp[name] = 1;
    }
  }
  string ans = "No";
  for (auto x : mp) {
    if (x.second >= 2) {
      ans = "Yes";
    }
  }
  cout << ans << endl;
}