//https://www.acmicpc.net/problem/2805

#include <iostream>
#include <vector>

using namespace std;
int t[1000000];

int main() {
	int n, m, h, max = 0;

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &t[i]);
		if (t[i] > max) max = t[i];
	}

	long long get = 0, low = 0, high = max, result = 0;

	while (low <= high) {
		h = (low + high) / 2;
		for (auto i : t)
			if (i > h)
				get += i - h;

		if (get >= m) result = result < h ? h : result;

		if (get > m) {
			low = h + 1;
			get = 0;
		}
		else if (get < m) {
			high = h - 1;
			get = 0;
		}
	}

	printf("%d", result);

	return 0;
}