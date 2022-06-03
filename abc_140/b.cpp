#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int N;
  cin >> N;
  vector<int> A(N);
  vector<int> B(N);
  vector<int> C(N-1);
  rep(i, N) {
    cin >> A.at(i);
  }
  rep(i, N) {
    cin >> B.at(i);
  }
  rep(i, N-1) {
    cin >> C.at(i);
  }

  int ans = 0;
  rep(i, N) {
    ans += B.at(A.at(i)-1);
    if (i != 0) {
      if(A.at(i) == (A.at(i - 1) + 1)){
        ans += C.at(A.at(i-1)-1);
      }
    }
  }
  cout << ans << endl;

}