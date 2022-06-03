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

  int a[N];
  rep(i, N) {
    cin >> a[i];
  }
  // gray: 0
  map<int, int> rating;
  bool has_red = false;
  rep(i, N) {
    if (a[i] < 400) {
      rating[0]++;
    } else if (a[i] < 800) {
      rating[1]++;
    } else if (a[i] < 1200) {
      rating[2]++;
    } else if (a[i] < 1600) {
      rating[3]++;
    } else if (a[i] < 2000) {
      rating[4]++;
    } else if (a[i] < 2400) {
      rating[5]++;
    } else if (a[i] < 2800) {
      rating[6]++;
    } else if (a[i] < 3200) {
      rating[7]++;
    } else {
      has_red = true;
      rating[8]++;
    }
  }
  // for (auto x : rating) {
  //   cout << x.first << endl;
  //   cout << x.second << endl;
  // }
  int min_ans;
  int max_ans;
  if (has_red) {
    min_ans = max(1, (int)rating.size() - 1);
    max_ans = (int)rating.size() - 1 + rating[8];
  } else {
    min_ans = (int) rating.size();
    max_ans = (int) rating.size();
  }
  cout << min_ans << " " << max_ans << endl;
}