//https://www.acmicpc.net/problem/2751

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n;

	scanf("%d", &n);

	vector<int> num(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);

	sort(num.begin(), num.end());

	for (auto i : num) printf("%d\n", i);

	return 0;
}