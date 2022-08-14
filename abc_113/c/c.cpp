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

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

int main()
{
  int N, M;
  cin >> N >> M;
  int P[M], Y[M];
  rep(i, M) {
    cin >> P[i] >> Y[i];
  }
  vector<int> cities(M);
  iota(cities.begin(), cities.end(), 0);
  sort(cities.begin(), cities.end(), [&](int i, int j) {
    if (P[i] == P[j]) {
      return Y[i] < Y[j];
    } else {
      return P[i] < P[j];
    }
  });
  debug(cities);
  map<int, int> city_count;
  vector<int> city_number(M);

  for(auto i: cities) {
    int current_pref = P[i];
    city_count[current_pref]++;
    city_number[i] = city_count[current_pref];
  }

  rep(i, M) {
    cout << setfill('0') << right << setw(6) << P[i];
    cout << setfill('0') << right << setw(6) << city_number[i];
    cout << endl;
  }
}