//https://www.acmicpc.net/problem/7568

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main() {
	int n, index = 0;
	cin >> n;

	vector<pair<int, int>> people;
	vector<int> order(n, 1);

	for (int i = 0; i < n; i++) {
		int weight, height;
		cin >> weight >> height;
		people.push_back({ weight, height });
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (people[i].first < people[j].first && people[i].second < people[j].second) {
				order[i]++;
			}
		}
	}

	for (auto i : order) cout << i << " ";

	return 0;
}