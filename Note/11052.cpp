//https://www.acmicpc.net/problem/11052

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, price, cnt = 0;
	vector<int> pack;
	vector<int> DP;

	pack.push_back(0);
	DP.push_back(0);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &price);
		pack.push_back(price);
		DP.push_back(0);
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			DP[i] = max(DP[i], DP[i - j] + pack[j]);

	cout << DP[n] << endl;

	return 0;
}