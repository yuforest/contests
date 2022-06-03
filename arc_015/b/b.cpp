// g++ -o b.out b.cpp -std=c++17
// oj d https://atcoder.jp/contests/arc_015/tasks/arc_015_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/arc_015/tasks/arc_015_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int N;
  cin >> N;
  double maxT[N];
  double minT[N];
  int mousyo = 0;
  int manatsu = 0;
  int natsubi = 0;
  int nettaiya = 0;
  int huyubi = 0;
  int mahuyubi = 0;
  for (int i = 0; i < N; ++i) {
    cin >> maxT[i];
    cin >> minT[i];
  }
  for (int i = 0; i < N; ++i) {
    if (maxT[i] >= 35.0) {
      mousyo++;
    }
    if (maxT[i] < 35.0 && maxT[i] >= 30.0) {
      manatsu++;
    }
    if (maxT[i] < 30.0 && maxT[i] >= 25.0) {
      natsubi++;
    }
    if (minT[i] >= 25.0) {
      nettaiya++;
    }
    if (minT[i] < 0.0 && maxT[i] >= 0.0) {
      huyubi++;
    }
    if (maxT[i] < 0.0) {
      mahuyubi++;
    }
  }

  cout << mousyo << " " << manatsu << " " << natsubi << " " << nettaiya << " " << huyubi << " " << mahuyubi << endl;
}