//Memoization and Dynamic programming
#include <math.h>
#include<iostream>
using namespace std;
int T, N, K;
long long dp[33][33][101];
long long permutate(int zeros, int ones, long long calc) {
	long long ret = 0;
	if (zeros + ones == N) {
		if (calc % K == 0)
			return 1;
		return 0;
	}
	if (dp[zeros][ones][calc] != -1)
		return dp[zeros][ones][calc];
	if (ones > 0 && zeros < N / 2) {
		ret += permutate(zeros + 1, ones, calc);
	}
	if (ones < N / 2)
		ret += permutate(zeros, ones + 1, (calc + (long long)pow(2.0, N - zeros - ones - 1)) % K);

	return dp[zeros][ones][calc] = ret;
}

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> K;
		if (N % 2 ==1 || K == 0){
			cout << "Case " << (i + 1) << ": 0" << endl;
			continue;
		}
		for (int j = 0; j < 33; j++)
			for (int l = 0; l < 33; l++)
				for (int m = 0; m < 101; m++)
					dp[j][l][m] = -1;
		cout << "Case " << (i + 1) << ": " << permutate(0, 0, 0) << endl;
	}
	return 0;
}
