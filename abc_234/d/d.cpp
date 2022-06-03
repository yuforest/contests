// g++ -o d.out d.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc233/tasks/abc233_d
// oj t -c "./d.out"
// oj s https://atcoder.jp/contests/abc233/tasks/abc233_d d.cpp


#include <bits/stdc++.h>
// #define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
long long minimum_time = 0;
vector<bool> used(200007, false);
vector<vector<int>> G1(10, vector<int>());
vector<vector<int>> G2(10, vector<int>());
long long K[200007];
long long T[200007];
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)

ll MAX = 1 << 18;

// #define rep(i,l,r) for(ll i=l;i<=r;i++)

int N;
ll X;
int L[100007];
vector<vector<ll>> a(100007, vector<ll>());
ll ans = 0;


int main() {
  int N, K;
  cin >> N >> K;
  K--;
  int P[N];
  rep (i, N) {
    cin >> P[i];
  }

  set<int> s;
  int kth_num;
  set<int>::iterator it;

  for (int i = 0; i < N; i++) {
    s.insert(P[i]);

    if (i == K) {
      it = s.begin();
      kth_num = *it;
      cout << kth_num << endl;
    } else if (i > K) {
      if (kth_num > P[i]) {
        cout << kth_num << endl;
        continue;
      } else {
        it++;
        kth_num = *it;
        cout << kth_num << endl;
      }
    }
  }
}


