//https://www.acmicpc.net/problem/11651

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

bool order(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) return a.first < b.first;
	else return a.second < b.second;
}

int main() {
	int n;
	scanf("%d", &n);

	vector<pair<int, int>> coordi;

	while (n--) {
		int x, y;
		scanf("%d %d", &x, &y);
		coordi.push_back({ x, y });
	}

	sort(coordi.begin(), coordi.end(), order);

	for (auto i : coordi) printf("%d %d\n", i.first, i.second);

	return 0;
}
