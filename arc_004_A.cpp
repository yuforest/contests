#include <bits/stdc++.h>
using namespace std;


int main()
{
	int N;
	cin >> N;
	vector<vector<int>> A(N, vector<int>(2, 0));

	for (int i = 0; i < N; i++) {
		cin >> A.at(i).at(0);
		cin >> A.at(i).at(1);
	}
	vector<double> result(pow(N, 2));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			double ans = (pow(A.at(i).at(0) - A.at(j).at(0), 2)) + (pow(A.at(i).at(1) - A.at(j).at(1), 2));
			ans = sqrt(ans);
			result.push_back(ans);
		}
	}
	// for (int i =0; i < result.size(); i++) {
	// 	cout << result.at(i) << endl;
	// }
	double answer = *max_element(result.begin(), result.end());
	cout << answer << endl;
}
