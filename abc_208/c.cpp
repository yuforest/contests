#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2000;
vector<vector<int>> G;
bool temp[MAX_N];

struct Data
{
  int index; // index, 元の位置
  int num;    // 国民番号

};

bool num_cmp(const struct Data &left, const struct Data &right)
{
  return left.num < right.num;
}

int main()
{
  long long  N, K;
  cin >> N >> K;
  vector<int> a(N, 0);
  for (int i = 0; i < N; i++)
  {
    cin >> a.at(i);
  }
  vector<Data> d(N);
  for (int i = 0; i < N; i++)
  {
    d.at(i).index = i; // 1,2,3,...となるようにする
    d.at(i).num = a.at(i);
  }
  sort(d.begin(), d.end(), num_cmp);
  vector<long long> snacks(N, 0);

  long long remains;
  if (K >= N) {
    long long  all = K / N;
    remains = K % N;
    for (int i = 0; i < N; i++)
    {
      snacks.at(i) = all;
    }
  } else {
    remains = K;
  }
  for (int i = 0; i < remains; i++) {
    int index = d[i].index;
    // cout << index << endl;
    snacks.at(index) += 1;
  }

  for (int i = 0; i < N; i++)
  {
    cout << snacks.at(i) << endl;
  }
}