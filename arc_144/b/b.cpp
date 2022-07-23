// g++ -o b.out b.cpp -std=c++11
// oj d https://atcoder.jp/contests/abc216/tasks/abc216_b
// oj t -c "./b.out"
// oj s https://atcoder.jp/contests/abc216/tasks/abc216_b b.cpp


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int a[300300];
int main(){
	int A,B,n;
	cin>>n>>A>>B;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int l=1,r=1e9;
	while(l<r){
		int mid=(l+r+1)/2;
		ll sum=0;
		for(int i=1;i<=n;i++)
			sum += max(0, (a[i]-mid)/B);
		for(int i=1;i<=n;i++)
			sum -= max(0, (mid-a[i]+A-1)/A);
		if(sum>=0)
			l=mid;
		else r=mid-1;
	}
	cout<<l<<endl;
	return 0;
}