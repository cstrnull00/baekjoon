//https://www.acmicpc.net/problem/2609

#include <iostream>
using namespace std;

int main() {
	int n, m, r, s;

	scanf("%d %d", &n, &m);

	int i = 1;
	while (i <= n && i <= m) {
		if (n % i == 0 && m % i == 0) r = i;
		i++;
	}

	s = m / r * n / r * r;

	printf("%d\n%d", r, s);

	return 0;
}