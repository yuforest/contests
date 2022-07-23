// g++ -o a.out a.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc216/tasks/abc216_a
// oj t
// oj s https://atcoder.jp/contests/abc216/tasks/abc216_a a.cpp

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
string target = "keyence";
int main()
{
  string str;
  cin>>str;
	if(str == target){
		puts("YES");
		return 0;
	}
	int n = str.size();
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			//delete [i,j]
			string S = "";
			for(int k=0;k<n;k++){
				if(i<=k && k<=j){
					continue;
				}
				else S.push_back(str[k]);
			}
			if(S == target){
				puts("YES");
				return 0;
			}
		}
	}
	puts("NO");
}