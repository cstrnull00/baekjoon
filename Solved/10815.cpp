//https://www.acmicpc.net/problem/10815

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(int);

vector<int> num;

int main() {

	int N, M, input;
	vector<int> out;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &input);
		num.push_back(input);
	}

	sort(num.begin(), num.end());

	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &input);
		out.push_back(input);
	}

	for (int i = 0; i < M; i++) printf("%d\n", binarySearch(out[i]));

	return 0;
}

int binarySearch(int n) {
	int left = 0;
	int right = num.size() - 1;

	while (left <= right) {
		int mid = (left + right) / 2;

		if (n > num[mid]) left = mid + 1;
		else if (n < num[mid]) right = mid - 1;
		else if (n == num[mid]) return 1;
	}

	return 0;
}