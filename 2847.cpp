#include <stdio.h>

int main() {
	int n[100];
	int level, tmp, cnt = 0;

	scanf("%d", &level);
	for (int i = 0; i < level; i++)
		scanf("%d", &n[i]);

	for (int i = level - 1; i > 0; i--) {
		if (n[i] <= n[i - 1]) {
			tmp = n[i - 1] - n[i] + 1;
			n[i - 1] = n[i] - 1;
			cnt += tmp;
		}
	}

	printf("%d", cnt);

	return 0;
}