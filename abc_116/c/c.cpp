// g++ -o c.out c.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc226/tasks/abc226_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc226/tasks/abc226_c c.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
long long minimum_time = 0;
vector<bool> used(200007, false);
vector<int> G[1 << 18];
long long K[200007];
long long T[200007];

int main()
{
  int N;
  cin >> N;

  map<int, int> even_mp;
  map<int, int> odd_mp;
  int even_max = 0;
  int even_max_count = 0;
  int even_second_max = 0;
  int even_second_max_count = 0;
  int odd_max = 0;
  int odd_max_count = 0;
  int odd_second_max = 0;
  int odd_second_max_count = 0;
  int v[N+1];
  for (int i = 1; i <= N; i++) {
    int val;
    cin >> val;
    v[i] = val;
    if (i % 2 == 0) {
      even_mp[val]++;
    } else {
      odd_mp[val]++;
    }
  }

  // コーナーケースのチェック
  bool is_same = true;
  for (int i = 1; i < N; i++) {
    if (v[i] != v[i+1]) {
      is_same = false;
    }
  }
  if (is_same) {
    cout << N / 2 << endl;
    return 0;
  }

  for (auto x : even_mp) {
    if (x.second > even_second_max_count) {
      if (x.second > even_max_count) {
        even_second_max = even_max;
        even_second_max_count = even_max_count;
        even_max = x.first;
        even_max_count = x.second;
      } else {
        even_second_max = x.first;
        even_second_max_count = x.second;
      }
    }
  }
  for (auto x : odd_mp) {
    if (x.second > odd_second_max_count) {
      if (x.second > odd_max_count) {
        odd_second_max = odd_max;
        odd_second_max_count = odd_max_count;
        odd_max = x.first;
        odd_max_count = x.second;
      } else {
        odd_second_max = x.first;
        odd_second_max_count = x.second;
      }
    }
  }
  int ans;
  if (even_max == odd_max) {
    int ans1 = N - odd_max_count - even_second_max_count;
    int ans2 = N - even_max_count - odd_second_max_count;
    ans = min(ans1, ans2);
  } else {
    ans = N - odd_max_count - even_max_count;
  }
  cout << ans << endl;
}