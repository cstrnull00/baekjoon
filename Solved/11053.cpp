//https://www.acmicpc.net/problem/11053

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n, input, length = 0, dp_max;
	vector<int> a;
	int dp[1001];

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &input);
		a.push_back(input);
		dp_max = 0;
		
		for (int j = 0; j < a.size(); j++) {
			if (a[i] > a[j]) {
				if (dp_max < dp[j])
					dp_max = dp[j];
			}
		}
		dp[i] = dp_max + 1;
		length = max(length, dp[i]);
	}

	cout << length << endl;

	return 0;
}