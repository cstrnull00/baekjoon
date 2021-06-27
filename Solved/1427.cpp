//https://www.acmicpc.net/problem/1427

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N, i = 0, digit, result;
	int arr[10];

	scanf("%d", &N);

	while (N > 0) {
		arr[i] = N % 10;
		N /= 10;
		digit = i++;
	}

	sort(arr, arr + digit + 1, greater<>());

	result = arr[0];

	for (i = 1; i <= digit; i++) {
		result *= 10;
		result += arr[i];
	}

	cout << result << endl;

	return 0;
}