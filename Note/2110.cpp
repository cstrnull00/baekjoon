//https://www.acmicpc.net/problem/2110

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int c, n, home;
	vector<int> houses;

	scanf("%d %d", &n, &c);

	for (int i = 0; i < n; i++) {
		scanf("%d", &home);
		houses.push_back(home);
	}

	sort(houses.begin(), houses.end());

	int ans = 0;
	int low = 1, high = houses.back() - houses.front();

	while (low <= high) {
		int mid = (low + high) / 2;
		int cnt = 1;
		int prev = houses.front();

		for(int i = 1; i < n; i++)
			if (houses[i] - prev >= mid) {
				cnt++;
				prev = houses[i];
			}
		if (cnt >= c) {
			ans = max(ans, mid);
			low = mid + 1;
		}
		else high = mid - 1;
	}

	
	cout << ans;

	return 0;
}