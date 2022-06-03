#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int N, K;
  cin >> N >> K;
  vector<int> p;
  rep(i, K) {
    int d;
    cin >> d;
    rep(j, d) {
      int val;
      cin >> val;
      p.push_back(val);
    }
  }
  sort(p.begin(), p.end());
  p.erase(std::unique(p.begin(), p.end()), p.end());
  cout << N - p.size() << endl;
}
