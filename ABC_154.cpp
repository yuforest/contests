#include <bits/stdc++.h>
using namespace std;

void printVec(std::vector<int> &vec)
{
  std::cout << "";
  for (auto it = vec.begin(); it != vec.end(); ++it)
  {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}
int main() {
  // string S, T;
  // cin >> S >> T;
  // int A, B;
  // cin >> A >> B;
  // string U;
  // cin >> U;
  // if (U == S) {
  //   A -= 1;
  // } else {
  //   B -= 1;
  // }
  // cout << A << " " << B;

  // string S;
  // cin >> S;
  // int len;
  // len = S.length();
  // string ans;
  // for (int i = 0; i < len; i++) {
  //   ans += "x";
  // }
  // cout << ans << endl;

  // int N;
  // cin >> N;
  // vector<int> A(N, 0);
  // for (int i = 0; i < N; i++)
  // {
  //   int val;
  //   cin >> val;
  //   A.at(i) = val;
  // }
  // int org_len = A.size();
  // sort(A.begin(), A.end());
  // A.erase(unique(A.begin(), A.end()), A.end());
  // if (org_len == A.size())
  // {
  //   cout << "YES" << endl;
  // } else {
  //   cout << "NO" << endl;
  // }

  // int N, K;
  // cin >> N >> K;
  // vector<int> p(N, 0);
  // for (int i = 0; i < N; i++) {
  //   int val;
  //   cin >> val;
  //   p.at(i) = val;
  // }
  // vector<double> s(N+1, 0);
  // for (int i = 0; i < N; ++i) {
  //   s[i + 1] = s[i] + (1.0/2.0) * (1 + p[i]);
  // }
  // double res = 0;
  // for (int i = K; i <= N; i++) {
  //   double val;
  //   val = s[i] - s[i-K];
  //   res = max(res, val);
  // }
  // std::cout << std::fixed << setprecision(12) << res << endl;

  int N, K;
  cin >> N >> K;
  int div;
  while (true) {
    div = N / 10;
    if (div <= 10) {
      break;
    }
  }
  std::cout << div << endl;
}