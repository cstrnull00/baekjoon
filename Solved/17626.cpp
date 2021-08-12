//https://www.acmicpc.net/problem/17626

#include <iostream>

using namespace std;

int main() {
	int n, ans = 0;

	scanf("%d", &n);
	for (int i = 0; i*i <= n; i++) {
		for (int j = 0; j*j <= n; j++) {
			for (int k = 0; k*k <= n; k++) {
				for (int l = 0; l*l <= n; l++) {
					int sum = i * i + j * j + k * k + l * l;
					if (sum == n) {
						if (i != 0) ans++;
						if (j != 0) ans++;
						if (k != 0) ans++;
						if (l != 0) ans++;
						cout << ans;
						return 0;
					}
					if (sum > n) break;
				}
			}
		}
	}

	return 0;
}