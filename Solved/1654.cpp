//https://www.acmicpc.net/problem/1654

#include <iostream>
#include <vector>

using namespace std;

int main() {
	long long n, k, low = 1, high = -1, max = 0;

	scanf("%lld %lld", &k, &n);

	vector<int> p(k);
	for (int i = 0; i < k; i++) {
		scanf("%d", &p[i]);
		high = high < p[i] ? p[i] : high;
	}

	while (low <= high) {
		long long mid = (low + high) / 2;
		int cnt = 0;

		for (auto i : p)
			cnt += i / mid;

		if (cnt >= n) {
			max = max < mid ? mid : max;
			low = mid + 1;
		}
		else if (cnt < n) {
			high = mid - 1;
		}
	}

	cout << max;

	return 0;
}