//https://www.acmicpc.net/problem/9095

#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	int num[1001] = { 1, 1, 2, };

	while (n--) {
		int m;
		cin >> m;

		for (int i = 3; i <= m; i++)
			num[i] = num[i - 1] + num[i - 2] + num[i - 3];

		cout << num[m] << '\n';
	}


	return 0;
}