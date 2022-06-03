// g++ -o b.out b.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc231/tasks/abc231_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc231/tasks/abc231_b b.cpp


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
  rep (i , N) {
    cin >> S[i];
  }
  map<string, int> mp;
  rep (i , N) {
    string name = S[i];
    auto itr = mp.find(name);
    if( itr != mp.end() ) {
      mp[name]++;
    } else {
      mp[name] = 1;
    }
  }
  int maxCount = 0;
  string ans;
  for (auto x : mp) {
    if (x.second > maxCount) {
      maxCount = x.second;
      ans = x.first;
    }
  }
  cout << ans << endl;
}