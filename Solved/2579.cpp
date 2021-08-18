//https://www.acmicpc.net/problem/2579

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;

	cin >> n;
	vector<int> stair(n);
	vector<int> score(n);

	for (int i = 0; i < n; i++) cin >> stair[i];
	
	score[0] = stair[0];
	score[1] = stair[0] + stair[1];
	score[2] = max(stair[0] + stair[2], stair[1] + stair[2]);

	for (int i = 3; i < n; i++)
		score[i] = max(score[i - 2] + stair[i], score[i - 3] + stair[i] + stair[i - 1]);

	cout << score[n - 1];

	return 0;
}