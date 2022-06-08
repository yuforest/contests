// g++ -o c.out c.cpp -std=c++17
// oj d https://atcoder.jp/contests/abc233/tasks/abc233_c
// oj t -c "./c.out"
// oj s https://atcoder.jp/contests/abc233/tasks/abc233_c c.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
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


int main() {
  int N;
  string S;
  cin >> N >> S;
  list<int> linked_list;
  linked_list.push_back(0);
  auto itr = linked_list.begin();
  for (int i = 0; i < S.size(); i++) {
    if (S[i] == 'L') {
      itr = linked_list.insert(itr, i+1);
    } else {
      itr++;
      itr = linked_list.insert(itr, i+1);
    }
  }
  for(auto itr = linked_list.begin(); itr != linked_list.end(); ++itr) {
    if (itr != linked_list.begin()) {
      cout << " " << *itr;
    } else {
      cout << *itr;
    }
  }
  cout << endl;
  return 0;
}
