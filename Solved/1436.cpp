//https://www.acmicpc.net/problem/1436

#include <iostream>

using namespace std;

int main() {
	int n, i = 666, cnt = 0, tmp;
	cin >> n;

	while (cnt < n) {
		tmp = i;

		do {
			if (tmp % 1000 == 666) {
				cnt++;
				break;
			}
			tmp /= 10;
		} while (tmp > 0);

		i++;
	}
	
	cout << --i;

	return 0;
}