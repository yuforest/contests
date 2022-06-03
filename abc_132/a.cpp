#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  string S;
  cin >> S;
  char char1;
  int char1_count = 0;
  char char2;
  int char2_count = 0;
  rep(i, S.size()) {
    char1 = S.at(0);
    if (S.at(i) != char1) {
      char2 = S.at(i);
    }
  }
  rep(i, S.size()){
    if (S.at(i) == char1) {
      char1_count++;
    } else if (S.at(i) == char2) {
      char2_count++;
    } else {
      cout << "No" << endl;
      return 0;
    }
  }
  if (char1_count == 2 && char2_count == 2){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  // mapを使った解法
  // const string YES = "Yes";
  // const string NO = "No";
  // string S;
  // cin >> S;
  // map<char, int> ma;
  // for (auto c : S)
  //   ma[c]++;
  // for (auto pa : ma)
  // {
  //   if (pa.second != 2)
  //   {
  //     cout << NO << endl;
  //     return 0;
  //   }
  // }
  // cout << YES << endl;
  // return 0;
}