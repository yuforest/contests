// g++ -o b.out b.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc219/tasks/abc219_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc219/tasks/abc219_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int N, X, Y, Z;
  cin >> N >> X >> Y >> Z;
  vector<int> A(N);
  vector<int> B(N);
  rep(i, N) {
    cin >> A[i];
  }
  rep(i, N) {
    cin >> B[i];
  }

  vector<int> math(N);
	iota(math.begin(), math.end(), 0);
  sort(math.begin(), math.end(), [&](auto x, auto y) {
    if (A[x] == A[y]) {
      return x < y;
    } else {
      return A[x] > A[y];
    }
  });

  vector<int> english(N);
	iota(english.begin(), english.end(), 0);
  sort(english.begin(), english.end(), [&](auto x, auto y) {
    if (B[x] == B[y]) {
      return x < y;
    } else {
      return B[x] > B[y];
    }
  });

  vector<int> both(N);
	iota(both.begin(), both.end(), 0);
  sort(both.begin(), both.end(), [&](auto x, auto y) {
    if (A[x] + B[x] == A[y] + B[y]) {
      return x < y;
    } else {
      return A[x] + B[x] > A[y] + B[y];
    }
  });

  map<int, bool> mp;
  int math_count = 0;
  int english_count = 0;
  int both_count = 0;
  vector<int> ans;
  rep(i, N) {
    int student = math[i];
    if (math_count < X && !mp[student]) {
      ans.push_back(student);
      math_count++;
      mp[student] = true;
    }
  }
  rep(i, N) {
    int student = english[i];
    if (english_count < Y && !mp[student]) {
      ans.push_back(student);
      english_count++;
      mp[student] = true;
    }
  }
  rep(i, N) {
    int student = both[i];
    if (both_count < Z && !mp[student]) {
      ans.push_back(student);
      both_count++;
      mp[student] = true;
    }
  }
  // for(auto e: mp) {
  //   cout << e.first << endl;
  // }
  sort(ans.begin(), ans.end());
  rep(i, ans.size()) {
    cout << ans[i] + 1 << endl;
  }
}