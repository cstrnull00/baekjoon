//https://www.acmicpc.net/problem/1764

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	map<string, int> list;
	vector<string> enlist;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string name; cin >> name;
		list.insert({ name, i });
	}
	for (int i = 0; i < m; i++) {
		string name; cin >> name;
		if (list.find(name) != list.end()) {
			enlist.push_back(name);
		}
	}

	sort(enlist.begin(), enlist.end());

	cout << enlist.size() << '\n';
	for (auto i : enlist) cout << i << '\n';

	return 0;
}