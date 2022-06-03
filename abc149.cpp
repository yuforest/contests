#include <bits/stdc++.h>
using namespace std;

// vector<vector<int>> comb(vector<int> &v) {
// 	for (int i = 0; i < v.size(); i++) {
// 		v[i] = 1;
// 		v[i] = 1;
// 	}
// 	vector<vector<int>> result(v.size(), vector<int>(2, 0));
// 	for (int k = 1; k < v.size(); k++)
// 	{
// 		for (int j = 1; j < v.size() - 1; j++)
// 		{
// 			v[k] = (v[k - 1] + v[k - 1]);
// 		}
// 	}
// }

// bool isPrime(int n) {
// 	if (n <= 1) {
// 		return false;
// 	}

// 	// Check from 2 to n-1
// 	for (int i = 2; i < n; i++) {
// 		if (n % i == 0) {
// 			return false;
// 		}
// 	}

// 	return true;
// }
int main()
{
	// string S, T;
	// cin >> S >> T;
	// cout << T << S << endl;

	// long long A, B, K;
	// cin >> A >> B >> K;
	// long long ans_A, ans_B;
	// if (A <= K) {
	// 	ans_A = 0;
	// 	if (B <= K - A) {
	// 		ans_B = 0;
	// 	} else {
	// 		ans_B = B - (K - A);
	// 	}
	// } else {
	// 	ans_A = A - K;
	// 	ans_B = B;
	// }
	// cout << ans_A << " " << ans_B << endl;
	// int X;
	// cin >> X;

	// while (true) {
	// 	if (isPrime(X)) {
	// 		break;
	// 	}
	// 	X++;
	// }
	// cout << X << endl;

	// int N, K, R, S, P;
	// string T;
	// cin >> N >> K;
	// cin >> R >> S >> P;
	// cin >> T;

	// int sum = 0;

	// vector<int> result(N, 0);

	// for (int i = 0; i < N; i++) {
	// 	int score;
	// 	if (i <= K - 1) {
	// 		if (T.at(i) == 'r') {
	// 			score = P;
	// 		} else if (T.at(i) == 's') {
	// 			score = R;
	// 		} else if (T.at(i) == 'p') {
	// 			score = S;
	// 		}
	// 	} else {
	// 		if (T.at(i - K) == 'r') {
	// 			if (T.at(i) == 'r') {
	// 				if (result.at(i - K) == 0) {
	// 					score = P;
	// 				} else {
	// 					score = 0;
	// 				}
	// 			} else if (T.at(i) == 's'){
	// 				score = R;
	// 			} else if (T.at(i) == 'p') {
	// 				score = S;
	// 			}
	// 		} else if (T.at(i - K) == 's') {
	// 			if (T.at(i) == 's') {
	// 				if (result.at(i - K) == 0)
	// 				{
	// 					score = R;
	// 				}
	// 				else
	// 				{
	// 					score = 0;
	// 				}
	// 			}
	// 			else if (T.at(i) == 'r')
	// 			{
	// 				score = P;
	// 			}
	// 			else if (T.at(i) == 'p')
	// 			{
	// 				score = S;
	// 			}
	// 		}
	// 		else if (T.at(i - K) == 'p') {
	// 			if (T.at(i) == 'p')
	// 			{
	// 				if (result.at(i - K) == 0)
	// 				{
	// 					score = S;
	// 				}
	// 				else
	// 				{
	// 					score = 0;
	// 				}
	// 			}
	// 			else if (T.at(i) == 'r')
	// 			{
	// 				score = P;
	// 			}
	// 			else if (T.at(i) == 's')
	// 			{
	// 				score = R;
	// 			}
	// 		}
	// 	}
	// 	// cout << score << endl;
	// 	result.at(i) = score;
	// 	sum += score;
	// }
	// cout << sum << endl;

	// int N, M;
	// cin >> N >> M;
	// vector<int> A(N, 0);
	// for (int i = 0; i < N; i++) {
	// 	cin >> A.at(i);
	// }

	// vector<vector<int>> A(M, vector<int　>(2, 0));
	// for (int i = 0; i << M; i++) {

	// }

	int N = 3;
	vector<int> v(N);
	iota(v.begin(), v.end(), 1); // v に 1, 2, ... N を設定
	do
	{
		for (auto x : v)
			cout << x << " ";
		cout << "\n";								// v の要素を表示
	} while (next_permutation(v.begin(), v.end())); // 次の順列を生成
	return 0;
}
