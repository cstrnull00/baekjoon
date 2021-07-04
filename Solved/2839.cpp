//https://www.acmicpc.net/problem/2839

#include <iostream>

using namespace std;

int main() {
	int n, num3 = 0, num5 = 0, tmp;
	int min = -1;

	scanf("%d", &n);

	while (num5 <= n / 5) {
		while (num3 <= n / 3) {
			tmp = 3 * num3 + 5 * num5;
			if (tmp == n && (min == -1 || min > num3 + num5))
				min = num3 + num5;
			num3++;
		}
		num3 = 0;
		num5++;
	}

	cout << min << endl;

	return 0;
}