//https://www.acmicpc.net/problem/1072

#include <cstdio>
#include <iostream>

int howManyGame(long long x, long long y);

int main() {
	long long x, y;

	scanf("%lld %lld", &x, &y);
	printf("%d", howManyGame(x, y));

	return 0;
}

int howManyGame(long long x, long long y) {
	int cnt, left, right, mid;
	int z, tmp;

	left = 0;
	right = 1000000000;

	z = (y * 100) / x;

	if (z >= 99) return -1;
	else {
		while (left <= right) {

			mid = (left + right) / 2;
			tmp = (y + mid) * 100 / (x + mid);

			if (z >= tmp) {
				cnt = mid;
				left = mid + 1;
			}
			else
				right = mid - 1;
		}

		return ++cnt;
	}
}