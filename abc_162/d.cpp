#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

void recursive_comb(int *indexes, int s, int rest, std::function<void(int *)> f) {
  if (rest == 0) {
    f(indexes);
  } else {
    if (s < 0) return;
    recursive_comb(indexes, s - 1, rest, f);
    indexes[rest - 1] = s;
    recursive_comb(indexes, s - 1, rest - 1, f);
  }
}

// nCkの組み合わせに対して処理を実行する
void foreach_comb(int n, int k, std::function<void(int *)> f) {
  int indexes[k];
  recursive_comb(indexes, n - 1, k, f);
}


int main()
{
  int N;
  cin >> N;
  string S;
  cin >> S;

  // for(int i = 1; i < N; i++) {

  // }
  
  // foreach_comb(N, 3, [](int *indexes) {
  //   // std::cout << indexes[0] << ',' << indexes[1] << ',' << indexes[2] << std::endl;
  //   if (indexes[1] - indexes[0] == indexes[2] - indexes[1]) {
  //   } else {
  //     if (S.at(indexes[0]) != S.at(indexes[1]) && S.at(indexes[0]) != S.at(indexes[2]) && S.at(indexes[1]) != S.at(indexes[2])) {
  //       sum += 1;
  //     }
  //   }
  // });
  vector<int> R(N);
  vector<int> G(N);
  vector<int> B(N);
  for (int i = 0; i < N; i++) {
    if (S.at(i) == 'R') {
      if (i == 0) {
        R.at(i) = 1;
        G.at(i) = 0;
        B.at(i) = 0;
      } else {
        R.at(i) = R.at(i-1) + 1;
        G.at(i) = G.at(i-1);
        B.at(i) = B.at(i-1);
      }
    } else if(S.at(i) == 'G') {
      if (i == 0) {
        R.at(i) = 0;
        G.at(i) = 1;
        B.at(i) = 0;
      } else {
        R.at(i) = R.at(i-1);
        G.at(i) = G.at(i-1) + 1;
        B.at(i) = B.at(i-1);
      }
    } else {
      if (i == 0) {
        R.at(i) = 0;
        G.at(i) = 0;
        B.at(i) = 1;
      } else {
        R.at(i) = R.at(i-1);
        G.at(i) = G.at(i-1);
        B.at(i) = B.at(i-1) + 1;
      }
    }
  }
  ll sum = 0;
  for(int i=0; i<N; i++) {
    for(int j=i+1; j<N; j++) {
      if (S.at(i) == S.at(j)) {
        continue;
      }
      if (S.at(i) == 'R' && S.at(j) == 'G') {
        sum += B.at(N-1) - B.at(j);
        if (j+(j-i) > N-1) {
          continue;
        }
        if (S.at(j+(j-i)) == 'B') {
          sum--;
        }
      }
      if (S.at(i) == 'R' && S.at(j) == 'B') {
        sum += G.at(N-1) - G.at(j);
        if (j+(j-i) > N-1) {
          continue;
        }
        if (S.at(j+(j-i)) == 'G') {
          sum--;
        }
      }
      if (S.at(i) == 'G' && S.at(j) == 'B') {
        sum += R.at(N-1) - R.at(j);
        if (j+(j-i) > N-1) {
          continue;
        }
        if (S.at(j+(j-i)) == 'R') {
          sum--;
        }
      }
      if (S.at(i) == 'G' && S.at(j) == 'R') {
        sum += B.at(N-1) - B.at(j);
        if (j+(j-i) > N-1) {
          continue;
        }
        if (S.at(j+(j-i)) == 'B') {
          sum--;
        }
      }
      if (S.at(i) == 'B' && S.at(j) == 'G') {
        sum += R.at(N-1) - R.at(j);
        if (j+(j-i) > N-1) {
          continue;
        }
        if (S.at(j+(j-i)) == 'R') {
          sum--;
        }
      }
      if (S.at(i) == 'B' && S.at(j) == 'R') {
        sum += G.at(N-1) - G.at(j);
        if (j+(j-i) > N-1) {
          continue;
        }
        if (S.at(j+(j-i)) == 'G') {
          sum--;
        }
      }
      // for(int k=j+1; k<N; k++) {
      //   vector<int> a = {i, j, k};
      //   if (j - i == k - j) {
      //     continue;
      //   }
      //   if (S.at(i) != S.at(j) && S.at(j) != S.at(k) && S.at(i) != S.at(k)) {
      //     sum += 1;
      //   }
      // }
    }
  }
  cout << sum << endl;
}