#include<cstdio>
#include<iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> N;
	int memo_fibo[41];
	int T, input;

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d", &input);
		N.push_back(input);
	}

	memo_fibo[0] = 0;
	memo_fibo[1] = 1;

	for (int i = 2; i < 41; i++)
		memo_fibo[i] = memo_fibo[i - 2] + memo_fibo[i - 1];

	for (int i = 0; i < T; i++) {
		if (N[i] > 0)
			printf("%d %d\n", memo_fibo[N[i]-1], memo_fibo[N[i]]);
		else
			printf("%d %d\n", 1, 0);
	}

	return 0;
}