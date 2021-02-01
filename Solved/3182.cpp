#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void list_clear(int* origin, vector<int>* arr, int n) {
	if (arr->size() != 0)
		for (int i = 0; i < n; i++)
			arr->pop_back();
	for (int i = 0; i < n; i++)
		arr->push_back(origin[i]);
}

int main() {
	int N, max = 0, temp, ans = 0, index, cnt = 0;

	cin >> N;

	int *senpai = new int[N];
	vector<int> list;

	for (int i = 0; i < N; i++)
		scanf("%d", &senpai[i]);

	for (int i = 0; i < N; i++) {
		list_clear(senpai, &list, N);
		index = i + 1;
		while (list.at(index - 1) != -1) {
			temp = index;
			index = list.at(index - 1);
			cnt++;
			list.at(temp - 1) = -1;
		}
		if (cnt > max) {
			max = cnt;
			ans = i + 1;
		}
		cnt = 0;
	}

	cout << ans;

	delete[] senpai;

	return 0;
}