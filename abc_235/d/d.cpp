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

ll X;
int L[100007];
vector<vector<ll>> a(100007, vector<ll>());

long long A;
int N;
int ans = -1;

bool checked[1000007];

void dfs(long long current, int count) {
  // cout << current << endl;
  if (current == N) {
    if (ans == -1) {
      ans = count;
    } else {
      ans = min(ans, count);
    }
    return;
  }
  if (current > 1000001 || checked[current]) {
    return;
  }
  if (current <= 1000001) {
    checked[current] = true;
  }

  dfs(current * A, count + 1);

  if (current >= 10 && current % 10 != 0) {
    string strCurrent = to_string(current);
    long long strSize = strCurrent.size() - 1;
    long long lastNum = strCurrent[strSize] - '0';

    long long tmp = (current / 10) + lastNum * pow(10, strSize);

    dfs(tmp, count+1);
  }
}

int main() {
  cin >> A >> N;
  dfs(1, 0);
  cout << ans << endl;
}


