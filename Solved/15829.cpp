//https://www.acmicpc.net/problem/15829

#include <iostream>

using namespace std;

int main() {
	int n;
	long long H = 0, i = 1;
	cin >> n;

	getchar();
	while (n--) {
		char c = getchar();
		H += (long long)(c - 'a' + 1) * i % 1234567891;
		i *= 31;
		i %= 1234567891;
	}

	cout << H % 1234567891;

	return 0;
}