#include <bits/stdc++.h>
using namespace std;

void recursive_comb(int *indexes, int s, int rest, std::function<void(int *)> f)
{
  if (rest == 0)
  {
    f(indexes);
  }
  else
  {
    if (s < 0)
      return;
    recursive_comb(indexes, s - 1, rest, f);
    indexes[rest - 1] = s;
    recursive_comb(indexes, s - 1, rest - 1, f);
  }
}

// nCkの組み合わせに対して処理を実行する
void foreach_comb(int n, int k, std::function<void(int *)> f)
{
  int indexes[k];
  recursive_comb(indexes, n - 1, k, f);
}

std::vector<std::vector<long long>> comb(int n, int r)
{
  std::vector<std::vector<long long>> v(n + 1, std::vector<long long>(n + 1, 0));
  for (int i = 0; i < v.size(); i++)
  {
    v[i][0] = 1;
    v[i][i] = 1;
  }
  for (int j = 1; j < v.size(); j++)
  {
    for (int k = 1; k < j; k++)
    {
      v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
    }
  }
  return v;
}
void printVector(const vector<int> &vec)
{
  for (int value : vec)
  {
    cout << value << " ";
  }
  cout << endl;
}

template <class T>
void combination(const vector<T> &seed, int target_size, bool (*callback)(const vector<T> &))
{
  vector<int> indices(target_size);
  const int seed_size = seed.size();
  int start_index = 0;
  int size = 0;

  while (size >= 0)
  {
    for (int i = start_index; i < seed_size; ++i)
    {
      indices[size++] = i;
      if (size == target_size)
      {
        vector<T> comb(target_size);
        for (int x = 0; x < target_size; ++x)
        {
          comb[x] = seed[indices[x]];
        }
        if (callback(comb))
          return;
        break;
      }
    }
    --size;
    if (size < 0)
      break;
    start_index = indices[size] + 1;
  }
}

bool my_callback(const vector<int> &comb)
{
  int n = comb.size();
  for (int i = 0; i < n; ++i)
    cout << comb[i] << " ";
  cout << endl;
  return false;
}

int main() {
  // int A,B,C;

  // cin >> A >> B >> C;
  // if (A == B  && B == C && C == A) {
  //   cout << "No" << endl;
  // } 
  // else if (A != B && B != C && A != C)
  // {
  //   cout << "No" << endl;
  // }
  // else {
  //   cout << "Yes" << endl;
  // }
  // int N;
  // cin >> N;
  // vector<int> A(N);
  // for (int i = 0; i < N; i++) {
  //   cin >> A.at(i);
  // }
  // string ans = "APPROVED";
  // for (int i = 0; i < N; i++)
  // {
  //   if (A.at(i) % 2 != 0) {
  //     continue;
  //   }
  //   if (A.at(i) % 3 == 0 || A.at(i) % 5 == 0) {
  //     continue;
  //   } else {
  //     ans = "DENIED";
  //     break;
  //   }
  // }
  // cout << ans << endl;
  // int N;
  // cin >> N;
  // vector<string> S(N);
  // map<string, int> count;
  // for (int i = 0; i < N; i++) {
  //   cin >> S.at(i);
  // }
  // for (int i = 0; i < N; i++)
  // {
  //   if (count.count(S.at(i)) == 0) {
  //     count[S.at(i)] = 1;
  //   } else {
  //     count[S.at(i)] += 1;
  //   }
  // }
  // int max_num = 0;
  // int pre_max = 0;
  // vector<string> ans;
  // for (auto it = count.begin(); it != count.end(); ++it) {
  //   max_num = max(max_num, it->second);
  //   if (pre_max < it->second) {
  //     ans = {};
  //   }
  //   if (it->second == max_num) {
  //     ans.push_back(it->first);
  //   }
  //   pre_max = max(max_num, it->second);
  // }
  // for (int i = 0; i < ans.size(); i++) {
  //   cout << ans.at(i) << endl;
  // }

  int N, K;
  cin >> N;
  cin >> K;
  vector<int> A(N);
  int max_pair = N * (N-1) / 2;
  vector<long long> cal(max_pair);

  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }

  combination(A, 2, my_callback);
}