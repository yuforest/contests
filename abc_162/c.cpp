#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int gcm(int a, int b) {
	int result = a;
	int k = 0;
	int n = b;
	do {
		k = result % n;
		result = n;
		n = k;
	} while(k != 0);
	return result;
}
int lcm(int a, int b) {
	int g;
	g = gcm(a, b);
	return a*b/g;
}
int lcm_n(vector<int> &numbers) {
	int l;
	l = numbers[0];
	for (int i = 1; i < numbers.size(); i++) {
		l = lcm(l, numbers[i]);
	}
	return l;
}
int gcm_n(vector<int> &numbers) {
  int l;
	l = numbers[0];
	for (int i = 1; i < numbers.size(); i++) {
		l = gcm(l, numbers[i]);
	}
	return l;
}
int main()
{
  int K;
  cin >> K;
  ll sum = 0;
  for(int i=1; i<=K; i++) {
    for(int j=1; j<=K; j++) {
      for(int k=1; k<=K; k++) {
        vector<int> a = {i, j, k};
        ll tmp;
        if (i == j == k) {
          tmp = i;
        } else if (i == 1 || j == 1 || k == 1) {
          tmp = 1;
        } else {
          tmp = gcm_n(a);
        }
        // cout << i <<  j << k << endl;
        // cout << tmp << endl;
        // cout <<  "-----" << endl;
        sum += tmp;
      }
    }
  }
  cout << sum << endl;
  
}
