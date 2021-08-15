//https://www.acmicpc.net/problem/1676

#include <iostream>

using namespace std;

int main() {
	int n, cnt2 = 0, cnt5 = 0, fact;

	cin >> n;

	while (n != 0) {
		if (n % 2 == 0) cnt2++;
		if (n % 125 == 0) cnt5 += 3;
		else if (n % 25 == 0) cnt5 += 2;
		else if (n % 5 == 0) cnt5++;
		n--;
	}

	fact = cnt2 >= cnt5 ? cnt5 : cnt2;

	cout << fact;

	return 0;
}