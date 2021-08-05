//https://www.acmicpc.net/problem/2108

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool order(pair<int, int> x, pair<int, int> y) {
	if (x.second == y.second) return x.first < y.first;
	else return x.second > y.second;
}

int main() {
	int n, sum = 0;

	scanf("%d", &n);

	vector<int> data(n);

	int num[8001] = { 0, };
	bool not_first = false;
	int most = -4001, most_val;

	for (int i = 0; i < n; i++) {
		scanf("%d", &data[i]);
		sum += data[i];
		num[data[i] + 4000]++;
	}

	int avg = (sum + sum % n) / n;

	sort(data.begin(), data.end());

	for (int i = 0; i < 8001; i++) {
		if (num[i] == 0) continue;
		if (num[i] == most && not_first) {
			most_val = i - 4000;
			not_first = false;
		}
		if (num[i] > most) {
			most = num[i];
			most_val = i - 4000;
			not_first = true;
		}
	}
	
	cout << avg << endl;
	cout << data[n/2] << endl;
	cout << most_val << endl;
	cout << data.back() - data.front() << endl;

	return 0;
}